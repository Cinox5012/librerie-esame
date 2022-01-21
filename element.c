/*
 * element.c contiene delle funzioni utili
 * alcune vengono usate in list.c/.h
 *  KEEP ON KEEPING ON CINOX
*/


#include "element.h"

#include <stdio.h>
#include <string.h>


boolean isEqual(element e1,element e2){                         //la funzione ritorna 1(true) se e1==e2
   // return(e1==e2);                                                               //per element int
   if((e1.qualcosa==e2.qualcosa)&&(strcmp(e1.qualcosaltro,e2.qualcosaltro)==0))     //per element struct
       return true;
   else return false;
}

boolean isLess(element e1, element e2){                         //la funzione ritorna 1(true) se e1<e2
    //return(e1<e2);                                                                               //per element int
    if((e1.qualcosa<e2.qualcosa)/*&&((strlen(e1.qualcosaltro))<(strlen(e2.qualcosaltro)))*/)     //per element struct
        return true;
    else return false;
}
/*
 * in questo caso isLess controlla il valore dell'intero
 * e la lunghezza della stringa e restituisce true se e solo
 * se entrambi sono minori(&&)
 * personalizzare ad evenienza
 */

boolean isGreater(element e1, element e2){                         //la funzione ritorna 1(true) se e1>e2
    //return(e1>e2);                                                                               //per element int
    if((e1.qualcosa>e2.qualcosa)/*&&((strlen(e1.qualcosaltro))>(strlen(e2.qualcosaltro)))*/)     //per element struct
        return true;
    else return false;
}
/*
 *stessa cosa  di isLess per isGreater
 */

element getElement(){
    /*
        element el;
        scanf("%d",&el);        //per element int
        return el;
     */
    element el;
    puts("inserisci qualcosa");
    puts("inserisci qualcosaaltro");                                //per element struct
   scanf("%d %s",&(el.qualcosa),el.qualcosaltro);
    return el;
}

void showElement(element e1){
    //printf("%d",el);      //per element int
    printf("%d, %s",e1.qualcosa,e1.qualcosaltro);
}