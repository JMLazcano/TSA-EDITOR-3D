/*
 * Map.h
 *
 *
 *
 */

#ifndef MAP_H_
#define MAP_H_




typedef void * Type;

typedef unsigned int (*Hash) (Type, unsigned int);
typedef int (*CmpData)(Type, Type);

typedef struct strMap *Map;

Map map_create(int size, float density, float gFactor, Hash h, CmpData cmp);


void map_set(Map m, Type keyM,Type keyV, Type value);
Type map_get(Map m,Type keyM,Type keyV);
Type map_remove(Map m,Type keyM,Type keyV);
int map_size(Map m);
//void map_destroy(Map m);



#endif /* MAP_H_ */
