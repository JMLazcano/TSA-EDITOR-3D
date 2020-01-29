
#include "Archivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA Editor.h"
#include "List.h"
#include <malloc.h>
#define LONG_MAX_LINEA  1024



int vertex_num(char vertex2[], char string[]) {
    //printf("Entro vertex numero\n");
    char linea[1024];
    FILE *DATA;
    DATA = fopen(string, "rt");
    if ((DATA = fopen(string, "rt")) == NULL){
        perror(string);
    }
    int i=0;
    while (fgets(linea, LONG_MAX_LINEA, DATA) != NULL) {
        if(i==3) {
            strcpy(vertex2, linea);
        }
        i++;
    }
    char delimitador[] = " ";
    char *token = strtok(vertex2, delimitador);
    char tmp[10];
    int rr;
    i=0;
    if(token != NULL){
        while(token != NULL){
            if(i==2){
                strcpy(tmp,token);
            }
            token = strtok(NULL, delimitador);
            i++;
        }
    }
    fclose(DATA);

    rr=atoi(tmp);

    return rr;
}

int face_num(char fa[], char string[]){
    //printf("Entro triangulos numero\n");
    char linea[1024];
    FILE *DATA2;
    if ((DATA2 = fopen(string, "rt")) == NULL){
        perror(string);
    }
    int i=0;
    while (fgets(linea, LONG_MAX_LINEA, DATA2) != NULL) {
        if(i==7) {
            strcpy(fa, linea);
        }
        i++;
    }

    char delimitador[] = " ";
    char *token = strtok(fa, delimitador);
    char tmp[10];
    int r;
    i=0;
    if(token != NULL){
        while(token != NULL){
            if(i==2){
                strcpy(tmp,token);
            }
            token = strtok(NULL, delimitador);
            i++;
        }
    }
    fclose(DATA2);

    r=atoi(tmp);
    return r;
}

void array_float( int vrt2, int k2, Vertex *array,char string[]){
    int il=0,arch=0;
    char linea[1024];
    char TMMP[]={};
    FILE *DATA3;
    DATA3 = fopen(string, "rt");
    while (fgets(linea, LONG_MAX_LINEA, DATA3) != NULL) {
        if((il>9)&&(il<=(9+vrt2))){
            arch=0;
            strcpy(TMMP,linea);
             char delimitador[] = " ";
             char *token = strtok(TMMP, delimitador);
            if(token!=NULL){
             while(token != NULL){
                if(arch==0){
                    array[k2].x=(float)atof(token);

                }
                 if(arch==1){
                     array[k2].y=(float)atof(token);

                 }
                 if(arch==2){
                     array[k2].z=(float)atof(token);

                 }
                 token = strtok(NULL, delimitador);
                 arch++;
             }
                array[k2].status=1;
             array[k2].keyV=il-10;//asignando llave unica
             k2++;
            }
        }


        il++;
    }

    for (int move = 0; move < k2-1; ++move) {
        array[move]=array[move+1];
        //printf("pocision 0-> X: %lf, Y: %lf, Z: %lf \n", array[move].x,array[move].y,array[move].z);
    }


    fclose(DATA3);


}
void triangulosArr(int vrt2,int fce2, int k3, Triangle *array,char string2[]){
    int il=0,txt=0;
    char linea[1024];
    char TMMP[]={};
    FILE *DATA3;
    DATA3 = fopen(string2, "rt");
    while (fgets(linea, LONG_MAX_LINEA, DATA3) != NULL) {
        if((il>9+vrt2)&&(il<=9+(vrt2+fce2))){
            txt=0;
            strcpy(TMMP,linea);
            char delimitador[] = " ";
            char *token = strtok(TMMP, delimitador);
            if(token!=NULL){
                while(token != NULL){
                    if(txt==1){
                        array[k3].v1=atoi(token);

                    }
                    if(txt==2){
                        array[k3].v2=atoi(token);

                    }
                    if(txt==3){
                        array[k3].v3=atoi(token);

                    }
                    token = strtok(NULL, delimitador);
                    txt++;
                }
                array[k3].status=1;
                array[k3].keyV=il-10-vrt2;
                array[k3].tableKeyV=-1;
                array[k3].tablekeyT=-1;

                k3++;
            }
        }
        il++;
    }

    for (int move = 0; move < k3-1; ++move) {
        array[move]=array[move+1];
        //printf("pocision 0-> v1: %d, v2: %d, v3: %d \n", array[move].v1,array[move].v2,array[move].v3);
    }

    fclose(DATA3);



}

void save_data(Vertex *ArrVert, Triangle *ArrTrin,Arch *archivox, char rut[]){

    FILE *dt;
    FILE *temporal;

    char linea[1024];
    char tmpp[1024];
    int apunta;
    //archivox->IndexVert+=2;
    char pl[100]="element vertex ", pl2[100]="element face ";
    char str[100], str2[100];
    sprintf(str, "%d", archivox->IndexVert);
    strcat(pl,str);
    strcat(pl,"\n");

    sprintf(str2, "%d", archivox->IndexTrian);
    strcat(pl2,str2);
    strcat(pl2,"\n");

    char arrfloatx[1024]={};
    char arrfloaty[1024]={};
    char arrfloatz[1024]={};

    char arrv1[1024]={};
    char arrv2[1024]={};
    char arrv3[1024]={};

    char genvert[1024];
    char gentr[1024];

    printf("\n");
    char temoply[1024];

    temporal=fopen("TempPly.ply", "wt+");
    dt=fopen(rut, "rt");
    while (fgets(linea, 1024, dt) != NULL) {
        fputs(linea,temporal);
    }
    fclose(dt);
    fclose(temporal);

    dt=fopen(rut, "wt+");
    temporal=fopen("TempPly.ply", "rt");
    apunta=0;
    while (fgets(temoply, 1024, temporal) != NULL) {
        strcpy(&tmpp[apunta], temoply);
        if(apunta>=0 && apunta<=2){
            fputs(&tmpp[apunta],dt);
        }

        else if(apunta==3){
            fputs(pl,dt);
        }


        else if(apunta>=4 && apunta<=6) {
            fputs(&tmpp[apunta], dt);
        }
        else if(apunta==7){
            fputs(pl2,dt);
        }
        else if(apunta>=8 && apunta<=9){
            fputs(&tmpp[apunta], dt);
        }
        else if((apunta>9)&&(apunta<=(9+archivox->IndexVert))){
            for (int i = 0; i <=apunta-10; ++i) {
                sprintf(arrfloatx, "%lf", ArrVert[i].x);
                sprintf(arrfloaty, "%lf", ArrVert[i].y);
                sprintf(arrfloatz, "%lf", ArrVert[i].z);
                strcat(arrfloatx," ");
                strcat(arrfloatx,arrfloaty);
                strcat(arrfloatx," ");
                strcat(arrfloatx,arrfloatz);
                strcpy(genvert,arrfloatx);
                strcat(genvert,"\n");
            }
            fputs(genvert,dt);
        }
        else if((apunta>(9+archivox->IndexVert))&&(apunta<=(9+archivox->IndexVert+archivox->IndexTrian))){
            for (int j = 0; j <=apunta-15; ++j) {
                sprintf(arrv1, "%d", ArrTrin[j].v1);
                sprintf(arrv2, "%d", ArrTrin[j].v2);
                sprintf(arrv3, "%d", ArrTrin[j].v3);
                strcat(arrv1," ");
                strcat(arrv1,arrv2);
                strcat(arrv1," ");
                strcat(arrv1,arrv3);
                strcpy(gentr,arrv1);
                strcat(gentr,"\n");
            }
            fputs("3 ",dt);
            fputs(gentr,dt);
        }
        apunta++;
    }

    fclose(dt);
    fclose(temporal);

}


void Archivo_ply(char rt[], Vertex *ArrVert, Triangle *ArrTrin,Arch *archivox, char *copiafile){


    char vertex[]={};
    char face[]={};
    char flotantes[]={};
    char triangulos[]={};
    Vertex VertTmp[]={};

    int vrt=0,fce=0,puntTr, k=1;//j es el indice de cantidad de trianguos y k vertices

    vrt= vertex_num(vertex, rt);
    //archivox.IndexVert=*(&vrt);
    //printf("vertices: %d\n", vrt);
    fce=face_num(face, rt);
    //printf("caras: %d\n", fce);
    //archivox.IndexTrian=*(&fce);
    //printf("caras: %d\n", archivox.IndexTrian);
    //printf("Lleva numeros\n\n");
    //fflush(stdout);
    //fflush(stdin);
    puntTr=1;
    /*ArrVert=(Vertex *)malloc(sizeof(Vertex)*vrt);
    ArrTrin=(Triangle *)malloc(sizeof(Triangle)*fce);*/

    array_float(*(&vrt), *(&k),ArrVert, rt);
    printf("\n");
    //printf("despues: X: %lf, Y: %lf, Z: %lf", ArrVert[0].x,ArrVert[0].y,ArrVert[0].z);


    printf("\n");
    //triangulosArr(*(&vrt),*(&fce), *(&j), ArrTrin, rt);
    triangulosArr(vrt,fce,puntTr, ArrTrin, rt);
    //printf("despues: v1: %d, v2: %d, v3: %d", ArrTrin[0].v1,ArrTrin[0].v2,ArrTrin[0].v3);


    archivox->IndexVert=vrt;
    archivox->IndexTrian=fce;


    //printf("\nnum vertice %d\n",archivox->IndexVert);

}