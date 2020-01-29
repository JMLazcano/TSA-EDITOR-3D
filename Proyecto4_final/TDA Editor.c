
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Map.h"
#include "TDA Editor.h"
#include "Archivos.h"

void add_tr_vrtp(int opcion,int vr, int fc, Vertex *ArrV, Triangle *ArrT,Arch *archivox){
    printf("%d id\n",opcion);
    if(opcion==1){
        for (int i = 0; i <fc ; ++i) {
            if(ArrT[i].status==0){
                printf("Ingresa el ID del primer Vertice: ");
                scanf("%d", &ArrT[i].v1);
                printf("Ingresa el ID del segundo Vertice: ");
                scanf("%d", &ArrT[i].v2);
                printf("Ingresa el ID del tercer Vertice: ");
                scanf("%d", &ArrT[i].v3);
                ArrT[i].status=1;
                archivox->IndexTrian++;
                ArrT[i+fc].keyV=i;
                ArrT[i+fc].tableKeyV=-1;
                printf("Triangulo (%d %d %d ) agregado\n\n",ArrT[i].v1,ArrT[i].v2,ArrT[i].v3);

                return;
            }else{
                printf("Los ids son menores a %d\n",archivox->IndexVert);
                printf("Ingresa el ID del primer Vertice: ");
                scanf("%d", &ArrT[fc+i].v1);
                printf("Ingresa el ID del segundo Vertice: ");
                scanf("%d", &ArrT[fc+i].v2);
                printf("Ingresa el ID del tercer Vertice: ");
                scanf("%d", &ArrT[fc+i].v3);

                ArrT[i+fc].status=1;
                archivox->IndexTrian++;
                ArrT[i+fc].keyV=i+fc;
                ArrT[i+fc].tableKeyV=-1;
                printf("Triangulo (%d %d %d ) agregado\n\n",ArrT[i+fc].v1,ArrT[i+fc].v2,ArrT[i+fc].v3);
                return;
            }

        }

    }
    else if(opcion==2){
        for (int i = 0; i <vr ; ++i) {
            if(ArrV[i].status==0){
                printf("Ingresa primer parametro x: ");
                scanf("%f", &ArrV[i].x);
                printf("Ingresa segundo parametro y: ");
                scanf("%f", &ArrV[i].y);
                printf("Ingresa tercer parametro z: ");
                scanf("%f", &ArrV[i].z);
                ArrV[i].status=1;
                printf("i= %d", i);
                ArrV[i].keyV=i+vr;
                ArrV[i].tableKeyV=-1;
                archivox->IndexVert++;
                printf("Vertice %d, (%f %f %f)\n\n",i+vr,ArrV[i].x,ArrV[i].y,ArrV[i].z);

                return;

            }else{
                printf("Ingresa primer parametro x: ");
                scanf("%f", &ArrV[i+vr].x);
                printf("Ingresa segundo parametro y: ");
                scanf("%f", &ArrV[i+vr].y);
                printf("Ingresa tercer parametro z: ");
                scanf("%f", &ArrV[i+vr].z);
                ArrV[i+vr].status=1;
                printf("Vertice %d, (%f %f %f)\n\n",i+vr,ArrV[i+vr].x,ArrV[i+vr].y,ArrV[i+vr].z);
                ArrV[i+vr].keyV=i+vr;
                ArrV[i+vr].tableKeyV=-1;
                archivox->IndexVert++;
                return;
            }

        }
    }
}

int EncontrarVertice( Vertex  *vertices,float px, float py, float pz, int size){
    if(vertices==NULL){
        printf("Error\n");
        return -1;
    }else{
        for(int i=0;i<size;i++){
            if(vertices[i].x == px)
                if(vertices[i].y == py)
                    if(vertices[i].z == pz)
                        return i;
        }
    }
    return -1;
}




int EncontrarTriangulo( Triangle *Arrtriangle,int v1, int v2, int v3, int size){
    int i;
    if(Arrtriangle==NULL){
        printf("Error\n");
        return -1;
    }else{
        for(i=0;i<size;i++){
            if(Arrtriangle[i].v1 == v1&&Arrtriangle[i].v2 == v2 && Arrtriangle[i].v3 == v3)

                break;
        }

        return i;
    }

};



void ID_T_V(Triangle *triangulos, int size, int v,Map m){
    if(triangulos == NULL)
        printf("Error\n");
    else{
        for(int i=0; i<size; i++){
            if(triangulos[i].v1  == v || triangulos[i].v2 == v || triangulos[i].v3 == v){
                triangulos[i].tableKeyV=v;
            }
            if(triangulos[i].tableKeyV>=0&& triangulos[i].tableKeyV<=size){
                map_set(m,(Type)&triangulos[i].tableKeyV,(Type)&triangulos[i].keyV, (Type)&triangulos[i]);
            }

        }
    }
}


void ID_TR_Neigh(Triangle *triangulos, int size,Map m1){
    if(triangulos == NULL)
        printf("Error\n");
    else{
        int t=0;
        for(int i=0;i<size;i++){
            for(t=0;t<size;t++){
                if(triangulos[i].v1==triangulos[t].v1 ||triangulos[i].v1==triangulos[t].v2 ||triangulos[i].v1==triangulos[t].v3 ){
                    if(triangulos[i].v2==triangulos[t].v1 ||triangulos[i].v2==triangulos[t].v2 ||triangulos[i].v2==triangulos[t].v3||triangulos[i].v3==triangulos[t].v1 ||triangulos[i].v3==triangulos[t].v2 ||triangulos[i].v3==triangulos[t].v3){

                        triangulos[i].tablekeyT=t;
                    }

                }else if(triangulos[i].v2==triangulos[t].v1 ||triangulos[i].v2==triangulos[t].v2 ||triangulos[i].v2==triangulos[t].v3 ){
                    if(triangulos[i].v1==triangulos[t].v1 ||triangulos[i].v1==triangulos[t].v2 ||triangulos[i].v1==triangulos[t].v3||triangulos[i].v3==triangulos[t].v1 ||triangulos[i].v3==triangulos[t].v2 ||triangulos[i].v3==triangulos[t].v3){

                        triangulos[i].tablekeyT=t;
                    }
                }else if(triangulos[i].v3==triangulos[t].v1 ||triangulos[i].v3==triangulos[i+1].v2 ||triangulos[i].v3==triangulos[i+1].v3 ){
                    if(triangulos[i].v2==triangulos[t].v1 ||triangulos[i].v2==triangulos[t].v2 ||triangulos[i].v2==triangulos[t].v3||triangulos[i].v1==triangulos[t].v1 ||triangulos[i].v1==triangulos[t].v2 ||triangulos[i].v1==triangulos[t].v3){

                        triangulos[i].tablekeyT=t;
                    }
                }
                //printf("Triangulo %d es vecino de %d\n",i,triangulos[i].tableKeyV);
                map_set(m1,(Type)&triangulos[i].tablekeyT,(Type)&triangulos[i].keyV, (Type)&triangulos[i]);
            }
        }
    }
}



void escalar3D(Vertex *vertices,int size,  float escala) {
    int i = 0;
    if (escala < 0)
        escala = escala * -1;
    if (escala == 0)
        printf("Error\n");
    else{
        for(int i=0; i< size; i++){
            vertices[i].x = vertices[i].x * escala;
            vertices[i].y = vertices[i].y * escala;
            vertices[i].z = vertices[i].z * escala;
        }
    }
}



void Borrar_Tr_P(Triangle *triangulos, int v1,int v2,int v3, int sizeV,int sizeT,Map mt,Map mv,Arch *archivox){

    int tdex=EncontrarTriangulo(triangulos,v1, v2, v3, sizeV);

    triangulos[tdex].status=0;

    Triangle *tmpsT;
    Triangle *tmpsT2;
    for(int i=0;i<sizeT;i++){
        tmpsT=(Triangle *)map_remove(mt,(Type)&i,(Type)&triangulos[tdex].keyV);
    }
    for(int j=0;j<sizeV;j++){
        tmpsT2=(Triangle *)map_remove(mv,(Type)&j,(Type)&triangulos[tdex].keyV);
    }
    archivox->IndexTrian=archivox->IndexTrian-1;
    printf("Triangulo %d (%d %d %d ) ha sido eliminado\n\n",tdex,triangulos[tdex].v1,triangulos[tdex].v2,triangulos[tdex].v3);


}


void Borrar_Vrtx(Vertex *vertices, Triangle *triangulos, int vertice, int sizeV,int sizeT,Map Mv, Map Mt,Arch *archivox){

    if (vertices == NULL && triangulos == NULL) {
        printf("Error\n");
        return;
    } else {
        printf("Vertice : %d ha sido eliminado!!\n\n",vertice);
        vertices[vertice].status=0;
        for (int i = 0; i < sizeT; i++) {
            if (triangulos[i].v1 == vertice || triangulos[i].v2 == vertice ||
                triangulos[i].v3 == vertice) {
                triangulos[i].status = 0;
                Borrar_Tr_P(triangulos, triangulos[i].v1,triangulos[i].v2,triangulos[i].v3, sizeV,sizeT,Mt, Mv,archivox);

            }
        }
        archivox->IndexVert=archivox->IndexVert-1;
    }
}

void Borrar_Arts(Vertex *vertices, Triangle *triangulos, int v1,int v2, int sizeV,int sizeT, Arch *archivoc,Map Mt, Map Mv){
    if (vertices == NULL && triangulos == NULL) {
        printf("Error\n");
        return;
    } else {

        printf("Arista formada por vertices %d y %d  Ha sido borrada\n\n",v1, v2);
        for (int i = 0; i < sizeT; i++) {
            if ((triangulos[i].v1 == v1 || triangulos[i].v2 == v1 ||
                 triangulos[i].v3 == v1) && (triangulos[i].v1 == v2 || triangulos[i].v2 == v2 ||
                                                triangulos[i].v3 == v2)) {
                triangulos[i].status = 0;
                Borrar_Tr_P(triangulos, triangulos[i].v1,triangulos[i].v2,triangulos[i].v3, sizeV,sizeT,Mt, Mv,archivoc);

            }
        }
    }
}

int MenuIni(){
    int i=0;
    printf("TDA Editor\n");
    printf("1. Enlistar Vertices\n");
    printf("2. Enlistar Triangulos\n");
    printf("3. Identificar triangulos vecinos\n");
    printf("4. Obtener identificador de triangulo\n");
    printf("5. Identificador triangulos por vertice\n");
    printf("6. Borrar puntos/vertice\n");
    printf("7. Borrar triangulo\n");
    printf("8. Borrar arista\n");
    printf("9. Anadir puntos y triangulos\n");
    printf("10. Escalar objeto 3D\n");
    printf("11. Guardar archivo\n");
    printf("12. Salir del programa\n");
    printf("Ingresa el numero correspondiente a la opcion: \n");
    scanf("%d",&i);
    return i;
};


void print_triangles(Triangle *trianArr, int size){
    int i;
    printf("Lista de triangulos, existen (%d)\n\n",size);
    for(i=0;i<size;i++){
        if(trianArr[i].status==1){
            printf("Triangulo, Sus vertices (%d, %d, %d) \n",trianArr[i].v1,trianArr[i].v2,trianArr[i].v3);
        }


    }
    printf("\n");
};
void print_vertices(Vertex *vertexArray, int size){
    int i;
    printf("Lista de Vertices, existen (%d)\n\n",size);
    for(i=0;i<size;i++){
        if(vertexArray[i].status==1){
            printf("Vertice id:%d, Sus coordenadas (%f, %f, %f) \n",i,vertexArray[i].x,vertexArray[i].y,vertexArray[i].z);
        }
    }
    printf("\n");
};

