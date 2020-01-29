

#ifndef LIST_H_
#define LIST_H_

typedef void *Type;
typedef struct strList *List;

List list_create();							//Crea una nueva instancia del contendedor List (reserva memoria dinámica, inicializa y retorna la direción de memoria)

int list_size(List l);						//Retorna el número de elementos que tiene la lista (l)

void list_add(List l, Type value);			//Agrega un nuevo elemento (value) al final de la lista (l)

Type list_get(List l, int p);				//Retorna el elemento (value) de la posición p que se encuentra en la lista (l)

void list_set(List l, Type value, int p);	//Asigna value al elemento de la posición p que se encuentra en la lista (l)

Type list_remove(List l, int p);			//Extrae de la lista el emelemento (value) que se encuentra en la posición p de la lista (l)

void list_destroy(List l);					//Destruye la lista, liberando toda la memoria dinámica

#endif /* LIST_H_ */

