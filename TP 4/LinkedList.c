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
    LinkedList* this= NULL;

    this = (LinkedList*) malloc (sizeof(LinkedList));

    if (this != NULL)
    {

        this->size = 0;
        this->pFirstNode = NULL;

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

    if (this != NULL)
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
    Node* actual = NULL;    //declaro variable para devolver

    if (this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this))     //valido que los datos recibidos sean validos
    {
        actual = this->pFirstNode;      //traigo direccion de memoria del primer elemento
        if (nodeIndex !=0)              //verifico que la lista tenga mas de un elemento
        {
            while (actual->pNextNode != NULL)   //recorro la lista, cuando pNextNode es NULL signifca que llego al final
            {
                actual = actual->pNextNode;     //actualizo valor por el siguiente
                nodeIndex --;
                if (nodeIndex == 0)              //valido que se haya llegado al indice solicitado
                {
                    break;
                }

            }

        }

    }

    return actual;
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
    return getNode(this, nodeIndex );
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
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;       //declaro variables
    Node* temporal = NULL;


    if (this !=NULL && nodeIndex >=0 && nodeIndex <= ll_len(this) )     //valido lista y tamaño
    {

        newNode = (Node*) malloc(sizeof(Node));         //asigno memoria
        temporal = (Node*) malloc(sizeof(Node));

        if (newNode != NULL && temporal != NULL)        //valido not null
        {

            newNode->pElement = pElement;               //cargo variable
            if (nodeIndex == 0)                         //Lista vacia
            {

                newNode->pNextNode = this->pFirstNode;  //swapeo y agrando lista
                this->pFirstNode = newNode;
                this->size++;
                returnAux = 0;


            }
            else
            {
                temporal = getNode(this, nodeIndex-1);      //traigo elemento del indice que se ocupara
                if (temporal !=NULL)
                {

                    newNode->pNextNode = temporal->pNextNode;       //swapeo y agrando lista
                    temporal->pNextNode = newNode;
                    this->size++;
                    returnAux = 0;

                }
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

    if (this != NULL)       //valido lista not null
    {

        if (ll_len(this)== 0)   // agrego elemento si la lista esta vacia
        {
            addNode(this, 0, pElement);
            returnAux = 0;


        }
        else                //agrego elemento si la lista tiene datos
        {

            addNode(this, ll_len(this), pElement);
            returnAux = 0;

        }

    }

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
    Node* nodo = (Node*) malloc(sizeof(Node));

    if (this != NULL && nodo != NULL && index < ll_len(this))
    {

        if (index == 0)
        {
            nodo = this->pFirstNode;
            if (nodo != NULL)
            {
                returnAux = nodo->pElement;
            }

        }
        else
        {

            nodo = getNode(this, index);
            if (nodo != NULL)
            {
                returnAux = nodo->pElement;
            }
        }

    }


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

    if (this != NULL && index >= 0 && index < ll_len(this))
    {

        if (index == ll_len(this))
        {
            ll_add(this, pElement);
            returnAux = 0;
        }
        else
        {
            getNode(this, index)->pElement = pElement;
            returnAux = 0;

        }
    }

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

    if (this != NULL && index >= 0 && index < ll_len(this))
    {



        if (index == 0 && this->pFirstNode != NULL)
        {

            if (getNode(this, index) != NULL)
            {
                this->pFirstNode = getNode(this, index)->pNextNode;
                free(getNode(this, index));
                this->size --;
                returnAux = 0;

            }

        }
        else if (index == ll_len(this))
        {

            if (getNode(this, index) != NULL && getNode(this, index-1) != NULL)
            {


                getNode(this, index-1)->pNextNode = NULL;
                free(getNode(this, index));
                this->size --;
                returnAux = 0;

            }

        }
        else
        {

            if (getNode(this, index) != NULL && getNode(this, index-1) != NULL)
            {
                Node* nodoDel = (Node*) malloc(sizeof(Node));

                if (nodoDel != NULL) {
                getNode(this, index-1)->pNextNode = getNode(this, index)->pNextNode;
                free(nodoDel);
                this->size --;
                returnAux = 0;
                }
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

    if (this != NULL)
    {

        for (int i=ll_len(this); i>0; i--)
        {

            ll_remove(this, ll_len(this)-1);
            returnAux = 0;

        }

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

    if (this != NULL)
    {

        if (ll_clear(this)==0)
        {
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

   // Node* element = (Node*) malloc(sizeof(Node));

    if (this != NULL /*&& element != NULL*/)
    {


        for (int i=0; i<ll_len(this); i++)
        {
         //   element = getNode(this, i);
            if (getNode(this, i)->pElement == pElement)
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

    if (this != NULL)
    {
        if (this->pFirstNode == NULL)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {

        addNode(this, index, pElement);
        returnAux = 0;
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

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
        if (index == 0)
        {

            returnAux = this->pFirstNode->pElement;
            ll_remove(this, index);
            free(this->pFirstNode);

        }
        else
        {


            if (getNode(this, index) != NULL )
            {
                returnAux = getNode(this, index)->pElement;
                ll_remove(this, index);
                free(getNode(this, index));
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
    Node* temporal;


    if (this != NULL)
    {
        returnAux = 0;
        for (int i=0; i<ll_len(this); i++)
        {
            temporal = getNode(this, i);

            if (temporal->pElement == pElement)
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
    int flag = 0;

    if (this != NULL && this2 != NULL)
    {
        for (int i=0; i< ll_len(this2); i++) {
                flag = 0;

            if (ll_contains(this, ll_get(this2, i))) {

                flag = 1;
                }


            if (!flag) {
                break;
            }

        }
        if (flag) {
            returnAux =1;
        } else {
            returnAux = 0;
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

    //   lista no null      from dentro de los indices              to dentro de los indices
    if (this != NULL && (from >= 0 && from < ll_len(this) ) && (to > from && to <= ll_len(this)) )
    {

        cloneArray = ll_newLinkedList();
        Node* element = (Node*) malloc(sizeof(Node));


        if (cloneArray != NULL && element !=NULL ) //lista no null
        {

            for (int i=from; i<to; i++) //recorro de from a to
            {
                element = getNode(this, i);
                ll_add(cloneArray, element->pElement); //agrego elemento en la nueva lista

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

    if (this != NULL)
    {

        cloneArray = ll_subList(this, 0, ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;

    if (this != NULL && (order == 0 || order == 1) && ll_len(this)>0 && pFunc != NULL)
    {

            Node* aux = (Node*) malloc(sizeof(Node));

        for (int i=0; i<ll_len(this)-1; i++)
        {

            if (getNode(this, i) != NULL && aux != NULL)
            {
                for (int j=i+1; j<ll_len(this); j++)
                {

                    if (getNode(this, j) != NULL)
                    {
                        if ((pFunc(getNode(this, i)->pElement, getNode(this, j) ->pElement) > 0 && order == 1)) {

                            aux->pElement = getNode(this, i)->pElement;
                            getNode(this, i)->pElement = getNode(this, j)->pElement;
                            getNode(this, j)->pElement = aux->pElement;


                        } else if ((pFunc(getNode(this, i)->pElement, getNode(this, j) ->pElement) < 0 && order == 0)) {

                            aux->pElement = getNode(this, i)->pElement;
                            getNode(this, i)->pElement = getNode(this, j)->pElement;
                            getNode(this, j)->pElement = aux->pElement;

                        }

                    }

                }

            }

        }


        free(aux);
        returnAux = 0;

    }

    return returnAux;

}

