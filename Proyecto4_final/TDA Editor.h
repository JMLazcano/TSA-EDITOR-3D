

#ifndef PROYECTO_PROYECTO_H
#define PROYECTO_PROYECTO_H



typedef struct{
    float x, y, z;
    unsigned int tableKeyV;
    unsigned int keyV;
    unsigned int status;
}Vertex;

Vertex * newVertex(float x, float y, float z);

typedef struct{
    int  v1, v2, v3;
    unsigned int tableKeyV,tablekeyT;
    unsigned int keyV;
    unsigned int status;

}Triangle;


typedef struct{
    unsigned IndexVert;
    unsigned int IndexTrian;
}Arch;


Triangle * newTriangle(int x, int y, int z);

typedef void * Type;

typedef unsigned int (*Hash) (Type, unsigned int);
typedef int (*CmpData)(Type, Type);

typedef struct strMap *Map;


typedef struct strVec3 *Vec3;

Vec3 vec3_create(float x, float y, float z);

int MenuIni();


int EncontrarVertice( Vertex  *vertices,float px, float py, float pz, int size);//identifica el id dependiendo del vertice
int EncontrarTriangulo( Triangle *Arrtriangle,int v1, int v2, int v3, int size);//Identifica el ID del triangulo
void ID_T_V(Triangle *triangulos, int size, int v,Map m);//identifica los triangulos que tocan un vertice: Crea una id del triángulo con respecto al vértice
void ID_TR_Neigh(Triangle *triangulos, int size,Map m1); //Crea una id del triangulo con respecto a sus triangulos vecinos
void escalar3D(Vertex *vertices,int size,  float escala);
void Borrar_Tr_P(Triangle *triangulos, int v1,int v2,int v3, int sizeV,int sizeT, Map mt,Map mv,Arch *archivox); //Elimina el triangulo correspondiente con respecto al vértice
void Borrar_Vrtx(Vertex *vertices, Triangle *triangulos, int vertice, int sizeV,int sizeT,Map Mv, Map Mt,Arch *archivox); //Elimina un vértice en específico
void Borrar_Arts(Vertex *vertices, Triangle *triangulos, int v1,int v2, int sizeV,int sizeT, Arch *archivoc,Map Mt, Map Mv); //Elimina la arista correspondiente, dandole dos puntos de referencia para poder ser eliminado
void add_tr_vrtp(int opcion,int vr, int fc, Vertex *ArrV, Triangle *ArrT,Arch *archivox);
void print_triangles(Triangle *trianArr, int size);
void print_vertices(Vertex *vertexArray, int size);

#endif //PROYECTO_PROYECTO_H
