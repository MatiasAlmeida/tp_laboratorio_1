/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); /// Reserva memoria para la primer posicion de la lista
int ll_len(LinkedList* this); /// Devuelve la cantidad de nodos actuales de la lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); /// Agrega un nuevo nodo con su elemento a la lista
void* ll_get(LinkedList* this, int index); /// Me devuelve cualquiera de los elementos de la lista por el ingreso de indice
int ll_set(LinkedList* this, int index,void* pElement); /// Me reemplaza el elemento de una posicion especifica de la lista por otro elemento
int ll_remove(LinkedList* this,int index); /// Elimina un elemento de la lista
int ll_clear(LinkedList* this); /// Elimina las referencias(nodos), pero no elimina los datos(elementos), aunque la memoria de esos nodos sigue estando reservada para posteriores usos
int ll_deleteLinkedList(LinkedList* this); /// Elimina las referencias y tambien las libera de la memoria
int ll_indexOf(LinkedList* this, void* pElement); /// Me devuelve el indice de un elemento
int ll_isEmpty(LinkedList* this); /// Me devuelve un valor si la lista esta vacia y otro si tiene al menos un elemento( -1 y 0 respectivamente)
int ll_push(LinkedList* this, int index, void* pElement); /// Me permite introducir un elemento a la lista en una posicion especifica sin pisar ningun dato
void* ll_pop(LinkedList* this,int index); /// Toma un elemento de la lista, lo elimina de su referencia(por lo tanto cambia el tamaño de la lista) y esta a cargo del programador lo que se pueda hacer con ese elemento
int ll_contains(LinkedList* this, void* pElement); /// Pregunta si la lista tiene un elemento en especifico
int ll_containsAll(LinkedList* this,LinkedList* this2); /// Pregunta si la lista contiene una sublista de elementos de esa lista
LinkedList* ll_subList(LinkedList* this,int from,int to); /// Crea una sublista que va desde un elemento X a un elemento Y(exclusive, el elemento Y no se encuentra dentro de la sublista)
LinkedList* ll_clone(LinkedList* this); /// Crea una copia de una lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); /// Ordena una lista segun los criterios elegidos en el puntero a funcion
