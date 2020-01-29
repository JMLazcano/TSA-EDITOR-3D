

#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "List.h"

struct strHash{
	int size;
	float density;
	float gFactor;
	Hash hf;
	CmpData cmp;
	List *table;
};

typedef struct strHash HashTable;

struct strMap{
	HashTable ht;
};

typedef struct{
	Type key;
	Type value;
}KeyValue;


Map map_create(int size, float density, float gFactor, Hash h, CmpData cmp){
    Map newMap=(Map)malloc(sizeof(struct strMap));
    newMap->ht.size=size;
    newMap->ht.density=density;
    newMap->ht.gFactor=gFactor;
    newMap->ht.hf=h;
    newMap->ht.cmp=cmp;
    newMap->ht.table=(List *)calloc(size, sizeof(List));
    return newMap;
}

KeyValue * newKeyValue(Type key, Type value){
    KeyValue *kv=(KeyValue *)malloc(sizeof(KeyValue));
    kv->key=key;
    kv->value=value;
    return kv;
}

void map_set(Map m, Type keyM,Type keyV, Type value){
    if(m!=NULL){
        int index=m->ht.hf(keyM, m->ht.size);
        if(m->ht.table[index]==NULL){
            m->ht.table[index]=list_create();
            list_add(m->ht.table[index], newKeyValue(keyV, value));
            //printf("Tabla[%d]: %d \n",index, list_size(m->ht.table[index]));

        }
        else{
            //Busca si existe el dato
            int i;
            int s=list_size(m->ht.table[index]);
            KeyValue *data;
            for (i=0;i<s;i++){
                data=list_get(m->ht.table[index], i);
                if(m->ht.cmp(data->key, keyV)==0){

                    return;
                }

            }
            list_add(m->ht.table[index], newKeyValue(keyV, value));
            //printf("Tabla[%d]: %d \n",index, list_size(m->ht.table[index]));
        }
    }
}

Type map_get(Map m, Type keyM,Type keyV){
    if(m!=NULL){
        int index=m->ht.hf(keyM, m->ht.size);
        if(m->ht.table[index]==NULL){
            return NULL;
        }else{
            //Busca si existe el dato en la lista
            int i;
            int s=list_size(m->ht.table[index]);
            KeyValue *data;
            //KeyValue *array=(KeyValue *)malloc(sizeof(KeyValue)*s);
            //int n=0;
            for (i=0;i<s;i++){
                data=list_get(m->ht.table[index], i);
                if(m->ht.cmp(data->key, keyV)==0){
                    //array[n].value=data->value;
                    //array[n].value=data->value;
                    return data->value;
                    //n++;
                }

            }
            //return array;
            //return data->value;
        }
    }
    return NULL;
}

Type map_remove(Map m,Type keyM,Type keyV){
    if(m!=NULL){
        int index=m->ht.hf(keyM, m->ht.size);
        if(m->ht.table[index]==NULL){
            return NULL;
        }else{
            //Busca si existe el dato en la lista y elimina
            int i;
            int s=list_size(m->ht.table[index]);
            KeyValue *data;
            KeyValue *erased;
            for (i=0;i<s;i++){
                data=list_get(m->ht.table[index], i);
                if(m->ht.cmp(data->key, keyV)==0){
                    erased=list_remove(m->ht.table[index], i);
                    //printf("Tabla[%d]: %d \n",index, list_size(m->ht.table[index]));
                    return erased->value;

                }

            }
        }
    }
    return NULL;
}
int map_size(Map m){
    return m->ht.size;

}


