#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL){
    	this->pFirstNode=NULL;
		this->size=0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux;
    returnAux = -1;
    if(this!=NULL){
		returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *Retorna un puntero al nodo que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo.
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* pNodeActual=NULL;
	int len;
	int i;

	//retorno = (int*)-1;  //Error en el valor de retorno de <get> si la lista pasada es NULL el valor a retornar es (-1)

	if(this!=NULL)
	{
		len =ll_len(this);
		if(nodeIndex>=0 && nodeIndex<len)
		{
			pNodeActual = this->pFirstNode;
			for(i=0; i<nodeIndex;i++)
			{

				pNodeActual= pNodeActual->pNextNode;
			}

		}
	}

    return pNodeActual;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *Agrega un nodo en la posición indexNode. Verificando que el puntero this sea distinto de NULL
y que index sea positivo e inferior al tamaño del array. Si la verificación falla la función retorna
(-1) y si tiene éxito (0)
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux;
    returnAux = -1;
	Node* pNodeActual=NULL;
	Node* pNodeAnterior=NULL;
	Node* pNodeNuevo=NULL;
	int len;

	if(this!=NULL)
	{
		len =ll_len(this);
		if(nodeIndex>=0 && nodeIndex<=len)
		{
			pNodeNuevo = (Node*) malloc(sizeof(Node));
			if(pNodeNuevo !=NULL)
			{

				pNodeActual= getNode(this, nodeIndex);
				pNodeNuevo->pNextNode=pNodeActual;
				if(nodeIndex==0){
					this->pFirstNode= pNodeNuevo;
				}else{
					pNodeAnterior= getNode(this, nodeIndex-1);
					pNodeAnterior->pNextNode=pNodeNuevo;
				}
				this->size++;
				pNodeNuevo->pElement=pElement;
				returnAux = 0;
			}
		}

	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this!=NULL){
    	len=ll_len(this);
    	if(addNode(this,len,pElement)==0){
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxiliar;
    int len;

    if(this!=NULL){
    	len= ll_len(this);
    	if(index>=0 && index<len){
    		auxiliar = getNode(this, index);
    		if(auxiliar!=NULL){
   				returnAux = auxiliar->pElement;
    		}
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *Inserta un elemento en el LinkedList, en el índice especificado. Verificando que el puntero this
 *sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
 *falla la función retorna (-1) y si tiene éxito (0).
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxiliar;
    int len;

    if(this!=NULL){
    	len= ll_len(this);
		if(index>=0 && index<len){
			auxiliar = getNode(this, index);
			if(auxiliar!=NULL){
				auxiliar->pElement = pElement;
				returnAux = 0;
			}
		}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *Elimina un elemento del LinkedList, en el índice especificado. Verificando que el puntero this
 *sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
 *falla la función retorna (-1) y si tiene éxito (0).
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeActual;
    Node* pNodeAnterior;


    int len;

    if(this!=NULL){
    	len= ll_len(this);
    	if(index>=0 && index<len){
			pNodeActual = getNode(this, index);
    		if(pNodeActual!=NULL){
    			/*if(len==1){//chequear
					this->pFirstNode=NULL;
				}
				else
				{*///es lo que saqué
					if(index==0){
						this->pFirstNode= pNodeActual->pNextNode;//this pasaria a apuntar al proximo nodo o a NULL si no hay otro
					}else{
						pNodeAnterior= getNode(this, index-1);
						if(pNodeAnterior!=NULL){
							pNodeAnterior->pNextNode=pNodeActual->pNextNode;

						}
					}
				//}

				this->size--;
				returnAux = 0;
				free(pNodeActual);
			}
    	}
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *Borra todos los elementos de LinkedList. Verificando que el puntero this sea distinto de NULL.
 *Si la verificación falla la función retorna (-1) y si tiene éxito (0)
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;

    if(this!=NULL){
		len= ll_len(this);
		for(i=0;i<len;i++){
			ll_remove(this,0);
		}
		returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
    	if(ll_clear(this)==0){
			free(this);
			returnAux = 0;
    	}
	}

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int i;
    void* pElementAuxiliar;
    if(this!=NULL){
    	len= ll_len(this);
    	for(i=0;i<len;i++){
    		pElementAuxiliar = ll_get(this, i);
    		if(pElementAuxiliar == pElement){
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero this sea
 *distinto de NULL. Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene
 *elementos (0).
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this!=NULL){
    	len= ll_len(this);
    	returnAux = 0;
    	if(len==0){
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *Desplaza los elementos e inserta en la posición index. Verificando que el puntero this sea
 *distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación falla
 *la función retorna (-1) y si tiene éxito (0).
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this!=NULL){
    	len= ll_len(this);
		if(index>=0 && index<=len){
			if(addNode(this, index,pElement)==0){
				returnAux = 0;
			}
		}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
de la lista. Verificando que el puntero this sea distinto de NULL y que index sea positivo e
inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
retorna el elemento
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pElemento;
    int len;

    if(this!=NULL){
    	len= ll_len(this);
		if(index>=0 && index<=len){
			pElemento = ll_get(this,index);
				ll_remove(this,index);
				returnAux = pElemento;
		}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
puntero this sea distintos de NULL. Si la verificación falla la función retorna (-1) , si encuentra
el elemento (1) y si no lo encuentra (0).
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){
    	returnAux = 0;
    	if(ll_indexOf(this, pElement)!=-1){
    		returnAux = 1;
    	}
    }




    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    int i;
    void* pElementAuxiliar;
    if(this!=NULL && this2!=NULL){
    	len = ll_len(this2);
		returnAux = 1;
    	for(i=0;i<len;i++)
    	{
    		pElementAuxiliar = ll_get(this2, i);
    		if(ll_contains(this, pElementAuxiliar)==0){
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *Retorna un nuevo LinkedList con el subconjunto de elementos. Verificando que el puntero this
sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo
array.
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* nuevaLista;
    int len;
    int i;
    void* pElementAuxiliar;

    if(this!=NULL){
    	len= ll_len(this);
    	if(from <=len && from>=0 && to <=len && to>=0 ){
    		nuevaLista = ll_newLinkedList();
			if(nuevaLista!=NULL){
				for(i=from; i<to;i++){
					pElementAuxiliar = ll_get(this, i);
					if(ll_add(nuevaLista, pElementAuxiliar)==0){
						cloneArray = nuevaLista;
					}
				}
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
    if(this!=NULL){
    	len= ll_len(this);
    	cloneArray = ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int resultado;
	Node* pElement1;
	Node* pElement2;
	void* pElementAuxiliar;

	if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		for(int i=0;i<ll_len(this)-1;i++)
		{
			pElement1 = getNode(this, i);
			for(int j=i+1;j<ll_len(this);j++)
			{
				pElement2 = getNode(this, j);
				resultado = pFunc(pElement1->pElement, pElement2->pElement);
				if((resultado == 1 && order == 1) || (resultado == -1 && order == 0))
				{
					//0 son iguales // 1 pElement1> pElement2//-1 pElement1< pElement2
					pElementAuxiliar = pElement1->pElement;
					ll_set(this, i, pElement2->pElement);
					ll_set(this, j, pElementAuxiliar);
					returnAux = 0;
				}
			}
		}
	}

    return returnAux;

}

