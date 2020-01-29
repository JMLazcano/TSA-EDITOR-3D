

#ifndef RAYOS_FUNCTION_H
#define RAYOS_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA Editor.h"




int vertex_num(char vertex2[], char string[]);
int face_num(char fa[], char string[]);
void triangulosArr(int vrt2,int fce2, int k3, Triangle *array,char string2[]);
void array_float( int vrt2, int k2, Vertex *array,char string[]);
void Archivo_ply(char rt[], Vertex *ArrVert, Triangle *ArrTrin,Arch *archivox, char *copiafile);
void save_data(Vertex *ArrVert, Triangle *ArrTrin,Arch *archivox, char rut[]);


#endif //RAYOS_FUNCTION_H
