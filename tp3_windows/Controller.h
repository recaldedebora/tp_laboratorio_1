#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN_input.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_ID_loadFromBinary(char* path);
int controller_ID_saveAsBinary(char* path , int* id);


/*
 *
 -LinkedList* ll_newLinkedList(void) -> Crea y retorna un nuevo LinkedList. Es el constructor, ya
que en él crearemos la struct y daremos valores iniciales a los campos.OK

-void ll_deleteLinkedList(LinkedList* self) -> Elimina el LinkedList OK

-void ll_add(LinkedList* self , void* element) ->Agrega un elemento al final de LinkedList..OK

-void ll_remove(LinkedList* self , int index) ->Elimina un elemento en LinkedList, en el índice
especificado.

-void* ll_get(LinkedList* self , int index) ->Retorna un puntero al elemento que se encuentra en el
índice especificado. OK

-int ll_len(LinkedList* self ) ->Retorna el tamaño del LinkedList.OK
 * */
