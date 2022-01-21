/*
 * element.c contiene le funzioni utili a lavorare con le liste
 * alcune dipendono da funzioni di element.c
 * che vanno modificate in base al tipo di element
 *  KEEP ON KEEPING ON CINOX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list emptyList(){           //costruttore della lista vuota
    return NULL;            //simply as that
}

boolean empty(list l){
    return (l==NULL);      //controlla se la lista è vuota, ritorna 1(true) se la lista è vuota
}

list cons(element e,list l){                                  //inserimento in testa della lista
    list t;
    t=(list) malloc(sizeof(item));
    if(t==NULL){                                                //controllo fallimento malloc
        perror("malloc fallita");
        //exit(1);
    }
    else {
        t->value = e;
        t->next = l;
    }
    return(t);
}

element head(list l){                                              //ritorna il primo elemento della lista
    if(empty(l)){
        perror("la lista è vuota");                              //se la lista è vuota stampa una errore
        exit(1);
    }
    else{
        return (l->value);
    }
}

list tail(list l){                                                 //ritorna la coda della lista
    if(empty(l)){
        perror("la lista è vuota");                              //se la lista è vuota stampa una errore
        exit(1);
    }
    else{
        return(l->next);
    }
}

void showlist(list l){                                              //stampa la lista che è stata passata
    printf("%s","[");                                        //si basa su showElement
    while(!empty(l)){                                               //funzione in element.c
        showElement(l->value);                                   //modificare lì
        l= tail(l);
        if(!empty(l))
            printf("%s",",");
    }
    puts("]");
}

boolean member(element e,list l){                                   //cerca l'elemento passato
    if(empty(l)) return false;                                      //ritorna 1(true) se elemento presente
    else if(isEqual(e, head(l))) return true;                //si basa su isEqual in element.c
    else return(member(e, tail(l)));                              //modificare lì
}

int length(list l){                                                  //ritorna il numero di elementi della lista
    if (empty(l)) return 0;
    else return (1+ length(tail(l)));
}

list append(list lista1, list lista2){                                //unisce due liste
   if(empty(lista1)) return lista2;
   else return(cons(head(lista1), append(tail(lista1),lista2)));
}

list reverse(list l) {                                                  //capovolge l'ordine di una lista
    if (empty(l)) return emptyList();
    else return append(reverse(tail(l)),cons(head(l), emptyList()));
}

list copy(list l) {                                                     //crea una copia della lista
    if (empty(l)) return l;
    else return cons(head(l), copy(tail(l)));
}

list delete(element e, list l) {                                        //cerca un elemento della lista e lo elimina
    if (empty(l)) return emptyList();
    else if (isEqual(e, head(l))) return tail(l);                //basata su isEqual in element.c
    else return cons(head(l), delete(e, tail(l)));              //modificare lì
}

list insord(element e,list l){                                          //inserisce un elemento ordinatamente,la lista deve essere già ordinata
        if (empty(l)) return cons(e, l);                                //basata su isLess in elemnt.c
        else if (isLess(e, head(l))==1) return cons(e, l);      //modificare lì,cambiare con isGreater per opposto
        else return cons(head(l), insord(e, tail(l)));
        /*if (empty(l))
            return cons(e,l);
        else if (isLess(e, head(l))==1)
            return cons(e,l);                                       //altra versione
        else
            return cons(l->value,insord( e,l->next));*/
}

list listSort(list l) {                                             //prende una lista e la ordina
    if (!empty(l)) {
        element e = head(l);                                        //l'ordine dipende da insord
        l = listSort(tail(l));
        l = insord(e,l);
    }
    else
        return l;
}