#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Map.h"
#include "TDA Editor.h"
#include "Archivos.h"

unsigned int hashFunction(Type key, unsigned int size);
int cmpData(Type d1, Type d2);


//typedef struct Triangle *TR;
//Vertex *v=(Vertex *)malloc(sizeof(Vertex));

int main(){
    setbuf(stdin,NULL);
    /*Vertex *vertL=(Vertex *)malloc(sizeof(Vertex)*vertices);
    Triangle *trinL=(Triangle *)malloc(sizeof(Triangle)*faces);*/
    //Ejemplo de uso de funciones
    //ID_T_V(trinL,faces,EncontrarVertice(vertL,vertL[0].x,vertL[0].y,vertL[0].z,vertices));
    //ID_TR_Neigh(trinL, faces);
    //escalar3D(vertL,vertices,  0.5);
    //ID_Tr_PorPuntos(trinL,faces, 2,  3, 0);
    //ID_Tr_PorPuntos(trinL,faces, 1,  2, 3);
	//Borrar_Tr_Vrtx(vertL, trinL, 6.25*0.5, 6.6*0.5, 6.2*0.5, vertices, faces);
    //Borrar_Vrtx(vertL, trinL, 6.25*0.5, 6.6*0.5, 6.2*0.5, vertices, faces);
    //Borrar_Arts(vertL, trinL, 6.25*0.5, 6.6*0.5, 6.2*0.5, 8.25*0.5, 6.6*0.5, 3.2*0.5, vertices, faces);

    /*

    Vertex *tmpcorrelo=(Vertex *)map_remove(m1,(Type)&k,(Type)&v1->keyV);
    printf("Se elimino: vertice %d :%f %f %f\n\n",tmpcorrelo->keyV,tmpcorrelo->x,tmpcorrelo->y,tmpcorrelo->z);

    */
    //Solicitud de ruta y archivo
    char ruta[256]="Z:\\Desktop\\figura.ply";
    char nombre_data[256];
    printf("Bienvenido\n");
    /*printf("Ingresa la ruta donde esta tu archivo(Con doble diagonal)> ");
    gets(ruta);
    printf("\n Ingresa el nombre delarchivo> ");
    gets(nombre_data);
    strcat(ruta, nombre_data);*/


    //Declaracion de arreglos
    Vertex *ArrVertices=(Vertex *)malloc(sizeof(Vertex)*100);//Arreglo de vertices
    Triangle *ArrTriangles=(Triangle *)malloc(sizeof(Triangle)*100);//Arreglo de triangulos
    Arch *archivo=(Arch *)malloc(sizeof(Arch));//Cantidad de Vaertices y caras
    char *copiafile=(char *)malloc(sizeof(char)*100);



    //Apertura de Archivos
    Archivo_ply(ruta,ArrVertices,ArrTriangles,archivo,copiafile);

    //printf("\nPRUEBA: despues: X2: %f, Y: %f, Z: %f\n", ArrVertices[0].x,ArrVertices[0].y,ArrVertices[0].z);
    //printf("llave %d status %d\n",ArrVertices[1].keyV,ArrVertices->status);


    //Uso de Mapas
    Map Mvp=map_create(60, 0.9, 0.5,hashFunction,cmpData);
    Map MT=map_create(60, 0.9, 0.5,hashFunction,cmpData);

    //Mapa vertices con lista triangulos
    int tx=0;
    int tv=0;
    int keytmp=0;
    Vertex *tempV;
    Triangle *tempT;

    for(tv=0;tv<archivo->IndexVert;tv++){
        ID_T_V(ArrTriangles, archivo->IndexTrian, ArrVertices[tv].keyV,Mvp);
    };
    printf("\n\n");

    ID_TR_Neigh(ArrTriangles, archivo->IndexTrian,MT);


    /*int tabla0=20;
    map_set(Mvp,(Type)&tabla0,(Type)&ArrVertices[0].keyV, (Type)&ArrVertices[0]);

    map_set(Mvp,(Type)&tabla0,(Type)&ArrVertices[1].keyV, (Type)&ArrVertices[1]);
    map_set(Mvp,(Type)&tabla0,(Type)&ArrVertices[1].keyV, (Type)&ArrVertices[1]);

    Vertex *tmp=(Vertex *)map_get(Mvp,(Type)&tabla0,(Type)&ArrVertices[0].keyV);
    Vertex *tmp1=(Vertex *)map_get(Mvp,(Type)&tabla0,(Type)&ArrVertices[1].keyV);
    printf("vertice %d, datos %f %f %f\n\n",tmp->keyV,tmp->x,tmp->y,tmp->z);*/



    /*Vertex *tmpcorrelo=(Vertex *)map_remove(m1,(Type)&k,(Type)&v1->keyV);
    printf("Se elimino: vertice %d :%f %f %f\n\n",tmpcorrelo->keyV,tmpcorrelo->x,tmpcorrelo->y,tmpcorrelo->z);
    */


    int menu=0;
    printf("\n\n");
    Vertex tmpV;
    Triangle tmpT;
    float escalar;
    int id,id2;
    int ciclo;

    do{

        menu = MenuIni();
        switch(menu){
            case 1: //Enlistar Vertices
                print_vertices(ArrVertices,archivo->IndexVert);
                break;
            case 2: //Enlistar Triangulos
                print_triangles(ArrTriangles,archivo->IndexTrian);
                break;
            case 3: //Identificar triangulos vecinos

                printf("\nIdentificar triangulos Vecinos,");
                printf(" Ingrese el identificador del triangulo>\n");
                scanf("%d",&id);
                printf("Triangulos vecinos al triangulo %d (%d %d %d), son: \n\n",id,ArrTriangles[id].v1,ArrTriangles[id].v2,ArrTriangles[id].v3);
                for(ciclo=0;ciclo<archivo->IndexTrian;ciclo++){
                    Triangle *tmpsT=(Triangle *)map_get(MT,(Type)&id,(Type)&ArrTriangles[ciclo].keyV);
                    if(tmpsT!=NULL){
                        printf("Triangulo %d (%d %d %d)\n",tmpsT->keyV,tmpsT->v1,tmpsT->v2,tmpsT->v3);
                    }
                }
                printf("\n");



                break;
            case 4://Obtener identificador de triangulo
                printf("\nIdentificador de triangulo,");
                printf(" Ingrese datos del triangulo>\n");
                printf("Ingrese el un vertice del Triangulo: ");
                scanf("%d",&tmpT.v1);
                printf("Ingrese otro vertice del Triangulo: ");
                scanf("%d",&tmpT.v2);
                printf("Ingrese otro vertice del Triangulo: ");
                scanf("%d",&tmpT.v3);
                id=EncontrarTriangulo(ArrTriangles, archivo->IndexTrian, tmpT.v1,tmpT.v2,tmpT.v3);
                if(id>=0&&id<=archivo->IndexTrian){
                    printf("El ID del triangulo Ingresado es: %d\n\n",id);
                }else{
                    printf("No existe Triangulo\n\n");
                }


                break;

            case 5://Identificador triangulos por vertice
                printf("\nIdentificar triangulos por vertice,");
                printf(" Ingrese el identificador del Vertice>\n");
                scanf("%d",&id);
                printf("Triangulos que usan el vertice: %d (%f %f %f), son: \n\n",id,ArrVertices[id].x,ArrVertices[id].y,ArrVertices[id].z);
                for(int y=0;y<archivo->IndexVert;y++){
                    Triangle *tmpsTx=(Triangle *)map_get(Mvp,(Type)&id,(Type)&ArrTriangles[y].keyV);
                    if(tmpsTx!=NULL){
                        printf("Triangulo %d (%d %d %d)\n",tmpsTx->keyV,tmpsTx->v1,tmpsTx->v2,tmpsTx->v3);
                    }
                }
                printf("\n");

                break;
            case 6://Borrar puntos/vertice
                printf("\nBorrar Vertices y todos los triangulos que lo tocan,");
                printf("Si no conoces el identificador, consulta la lista de vertices\n");
                printf(" Ingrese el identificador del Vertice>\n");
                scanf("%d",&id);

                Borrar_Vrtx(ArrVertices, ArrTriangles, id, archivo->IndexVert,archivo->IndexTrian,Mvp, MT,archivo);


                break;
            case 7://Borrar triangulo
                printf("\nBorrar Triangulo,");
                printf(" Ingrese datos del triangulo>\n");
                printf("Ingrese el un vertice del Triangulo: ");
                scanf("%d",&tmpT.v1);
                printf("Ingrese otro vertice del Triangulo: ");
                scanf("%d",&tmpT.v2);
                printf("Ingrese otro vertice del Triangulo: ");
                scanf("%d",&tmpT.v3);

                Borrar_Tr_P(ArrTriangles, tmpT.v1, tmpT.v2, tmpT.v3, archivo->IndexVert,archivo->IndexTrian,MT,Mvp,archivo);

                break;
            case 8://Borrar arista
               printf("\nBorrar Arista,");
                printf("Si no conoces el identificador, consulta la lista de vertices\n");
                printf(" Ingrese el identificador del primer Vertice>\n");
                scanf("%d",&id);
                printf(" Ingrese el identificador del segundo Vertice>\n");
                scanf("%d",&id2);

                Borrar_Arts(ArrVertices, ArrTriangles, id, id2, archivo->IndexVert,archivo->IndexTrian,archivo,MT,Mvp);

                printf("\n");

                break;
            case 9://Anadir puntos y triangulos
                printf("\nSelecciona la opcion (1)Agregar Triangulo, (2)Agregar vertice \n");
                scanf("%d",&id);

                add_tr_vrtp(id,archivo->IndexVert, archivo->IndexTrian, ArrVertices, ArrTriangles,archivo);
                fflush(stdin);

                for(tv=0;tv<archivo->IndexVert;tv++){
                    ID_T_V(ArrTriangles, archivo->IndexTrian, ArrVertices[tv].keyV,Mvp);
                };
                printf("\n\n");

                ID_TR_Neigh(ArrTriangles, archivo->IndexTrian,MT);


                break;
            case 10: //Escalar objeto 3D
                printf("Escalar la Figura>\n");
                printf("Ingrese el valor por lo que quiere escalar la figura: ");
                scanf("%f",&escalar);
                escalar3D(ArrVertices,archivo->IndexVert,  escalar);
                printf("Se incremento el tamano de la figura x%0.2f, \npor lo que el valor de los vertices cambio\n\n",escalar);


                break;
            case 11: //Salir y Guardar archivo
                save_data(ArrVertices, ArrTriangles,archivo,ruta);
                break;
            case 12:
                printf("Gracias por utilizar nuestro servicio\n");
                break;
            default:
                printf("Opcion equivoquada!!");
                break;
        }
    }while(menu!=12);


    return 0;
}


unsigned int hashFunction(Type key, unsigned int size){
	unsigned int *k= (unsigned int *)key;
	return *k%size;
}

int cmpData(Type d1, Type d2){
	int *v1=(int *)d1;
	int *v2=(int *)d2;
	return *v1-*v2;
}

Vertex * newVertex(float x, float y, float z){
	Vertex *v=(Vertex *)malloc(sizeof(Vertex));
	v->x=x;
	v->y=y;
	v->z=z;
	return v;
}



Triangle *newTriangle(int v1, int v2, int v3){
    Triangle *v=(Triangle *)malloc(sizeof(Triangle));
    v->v1=v1;
    v->v2=v2;
    v->v3=v3;
    return v;
}