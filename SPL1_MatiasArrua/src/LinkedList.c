#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
	 LinkedList* this = NULL;
	    this = (LinkedList*)malloc(sizeof(LinkedList));
	    if(this != NULL)
	    {
	        this->pFirstNode= NULL;
	        this->size= 0;
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
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode;
    int len;
    pNode = NULL;

    if(this != NULL && nodeIndex>=0)
    {
        len = ll_len(this);
        if(nodeIndex<len)
        {
            if(nodeIndex == 0)
            {
                pNode = this->pFirstNode;
            }
            else
            {
                pNode = this->pFirstNode;
                for(int i=0; i<len; i++)
                {
                    if(i == nodeIndex)
                    {
                        break;
                    }
                    pNode = pNode->pNextNode;

                }
            }
        }
    }
    return pNode;
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
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pPreviousNode = NULL;
    Node* pNewNode= (Node*) malloc(sizeof(Node));

     len = ll_len(this);

       if(this != NULL && nodeIndex>=0 && nodeIndex<=len){

    	   if(pNewNode != NULL){

    		   pNewNode->pElement = pElement;

    	   if(nodeIndex == 0){

    		   pNewNode->pNextNode = this->pFirstNode;
    		   this->pFirstNode = pNewNode;
    	   }
    	   else if(nodeIndex < len){
    		   nodeIndex = nodeIndex-1;
    		                  pPreviousNode = getNode(this, nodeIndex);
    		                  pNewNode->pNextNode = pPreviousNode->pNextNode;
    		                  pPreviousNode->pNextNode = pNewNode;
    	   }
    	   else if(nodeIndex==len)
    	   {
    		   nodeIndex = nodeIndex-1;
           pPreviousNode = getNode(this, nodeIndex);
           pPreviousNode->pNextNode = pNewNode;
           pNewNode->pNextNode = NULL;

    	   }

       }
    	   len++;
    	  this->size = len;
    	  returnAux = 0;
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

	    if(this!= NULL)
	    {
	        len = ll_len(this);
	        returnAux = addNode(this, len, pElement);
	    }

	    return returnAux;

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	 void* returnAux = NULL;
	    int len;
	    Node* pNode = NULL;

	    if(this != NULL)
	    {
	        len = ll_len(this);
	        if(index>=0 && index<len)
	        {
	            pNode = getNode(this, index);
	            if(pNode != NULL)
	            {
	                returnAux = pNode->pElement;


	            }
	        }
	    }
	    //free(pNode);
	    return returnAux;
	}


/** \brief Modifica un elemento de la lista
 *
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
	    int len;
	    Node* pNode = NULL;

	    if(this != NULL)
	    {
	        len = ll_len(this);
	        if(index>=0 && index<len)
	        {
	            pNode = getNode(this, index);
	            if(pNode != NULL)
	            {
	                pNode->pElement = pElement;
	                returnAux = 0;

	            }
	        }
	    }
	    free(pNode);
	    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	    int len;
	    Node* pNodeRemoved;
	    Node* pPreviousNode;
	    if(this != NULL)
	    {
	        len = ll_len(this);

	        pNodeRemoved = NULL;
	        pPreviousNode = NULL;

	        if(index>=0 && index<len)
	        {
	            pNodeRemoved = getNode(this, index);
	            if(pNodeRemoved != NULL)
	            {
	                if(index == 0)
	                {

	                    this->pFirstNode = pNodeRemoved->pNextNode;
	                    free(pNodeRemoved);
	                    pNodeRemoved = NULL;


	                }
	                else if(index<len)
	                {
	                    index = index - 1;
	                    pPreviousNode = getNode(this, index);
	                    pPreviousNode->pNextNode = pNodeRemoved->pNextNode;
	                    free(pNodeRemoved);
	                    pNodeRemoved = NULL;
	                }
	                else if (index == len)
	                {
	                    index = index-1;
	                    pPreviousNode = getNode(this, index);
	                    pPreviousNode->pNextNode = NULL;
	                    free(pNodeRemoved);
	                    pNodeRemoved = NULL;
	                }
	                len--;
	                this->size = len;
	                returnAux = 0;
	            }
	        }
	    }
	    return returnAux;
	}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int returnAux = -1;
	    int len;
	    if(this != NULL)
	    {
	        len = ll_len(this);
	        for(int i=0; i<len; i++)
	        {
	            ll_remove(this, i);
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
	    if(this != NULL)
	    {
	        ll_clear(this);
	        free(this);
	        this = NULL;
	        returnAux = 0;
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
	    void* pAux=NULL;
	    if(this != NULL)
	    {
	        len = ll_len(this);
	        for(i=0; i<len; i++)
	        {
	            pAux=ll_get(this,i);
	            if(pAux == pElement)
	            {
	                returnAux = i;
	                break;
	            }
	        }
	    }
	    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
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
	    if(this != NULL)
	    {
	        len = ll_len(this);
	        if(len>0)
	        {
	            returnAux = 0;
	        }
	        else
	        {
	            returnAux = 1;
	        }
	    }
	    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
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
    int returnAdd = -1;
    if(this != NULL)
    {
        if(index>=0 && index <= ll_len(this))
        {
            returnAdd = addNode(this, index, pElement);
            if(returnAdd == 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}



/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
	    int retorno = -1;
	    if(this != NULL)
	    {
	        if(index>=0 && index < ll_len(this))
	        {
	            returnAux = ll_get(this, index);
	            retorno = ll_remove(this, index);
	            if(retorno != 0)
	            {
	                returnAux = NULL;
	            }
	        }
	    }
	    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;

	    Node* pNodeAux;
	    if(this != NULL)
	    {
	        pNodeAux = NULL;
	        returnAux = 0;
	        for(int i=0; i<ll_len(this); i++)
	        {
	            pNodeAux = ll_get(this, i);
	            if(pNodeAux == pElement)
	            {
	                returnAux = 1;
	                break;
	            }
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
	    int validate = -1;
	    Node* pNodeAux;
	    if(this != NULL && this2 != NULL)
	    {
	        returnAux = 1;
	        pNodeAux = NULL;
	        for(int i=0; i<ll_len(this2); i++)
	        {
	            pNodeAux = ll_get(this2, i);
	            validate = ll_contains(this, pNodeAux);
	            if(validate != 1)
	            {
	                returnAux = 0;
	                break;
	            }
	        }
	    }
	    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
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
	    void* pNodeAux;
	    if(this != NULL && (from>=0 &&(to>=from && to<=ll_len(this)) && from<=ll_len(this)) )
	    {
	        pNodeAux = NULL;
	        cloneArray = ll_newLinkedList();
	        if(cloneArray != NULL)
	        {
	            for(int i=from; i<to; i++)
	            {
	                pNodeAux = ll_get(this, i);
	                addNode(cloneArray,i, pNodeAux);
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
	    if(this != NULL)
	    {
	        cloneArray = ll_newLinkedList();
	        if(cloneArray != NULL)
	        {
	            cloneArray = ll_subList(this, 0, ll_len(this));
	        }
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
    int i;
    int j;
    void* aux;

    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
    	for(i=0;i<ll_len(this)-1;i++)
    	{
    		for(j=i+1;j<ll_len(this);j++)
    		{
    			if(order==1)
    			{
    				if(pFunc(ll_get(this, i), ll_get(this, j))>0)
    				{
    					aux=ll_get(this, i);
    					ll_set(this, i, ll_get(this, j));
    					ll_set(this, j, aux);
    					returnAux=0;
    				}
    			}
    			else if(order==0)
    			{
    				if(pFunc(ll_get(this, i), ll_get(this, j))<0)
    				{
    					aux=ll_get(this, i);
    					ll_set(this, i, ll_get(this, j));
    					ll_set(this, j, aux);
    					returnAux=0;
    				}
    			}
    		}
    	}
    }
    return returnAux;

}
LinkedList* ll_map(LinkedList* this, void(*pFunc)(void* pElement)){
	if(this != NULL && pFunc != NULL){
		for(int i=0;i <ll_len(this);i++){
			pFunc(ll_get(this,i));

		}
	}
	return this;
}
