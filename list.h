/*
 * in list.h avviene la dichiarazione del tipo list
 * e vengono dichiarate delle funzioni utili a lavorare con esse
 * le primitive sono indipendenti dal tipo element
 * alcune non primitive dipendono invece dall'elemento
 *  KEEP ON KEEPING ON CINOX
*/

#include "element.h"


//#ifndef CREAZIONE_TEST_LIBRERIE_LIST_H
//#define CREAZIONE_TEST_LIBRERIE_LIST_H

typedef struct list_element{
    element value;                                           //dichiarazione di list_element,
    struct list_element* next;                               // un "cella" di list
}item;                                                       //il tipo sarà item

typedef item* list;                                         //dichiarazione di item

//PRIMITIVE

list emptyList();
boolean empty(list l);
list cons(element e,list l);
element head(list l);
list tail(list l);

//NON PRIMITIVE

void showlist(list l);
boolean member(element e,list l);
int length(list l);
list append(list lista1,list lista2);
list reverse(list l);
list copy(list l);
list delete(element e,list l);
list insord(element e,list l);
list listSort(list l);

//#endif //CREAZIONE_TEST_LIBRERIE_LIST_H
