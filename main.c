/*
 * Questo workspace è atto alla creazione e test delle mie librerie
 * in particolare a "list.c"; "list.h"; "element.h";"element.c".
 * le librerie saranno poi sia su ~/CODE2/librerie sia su github
 * KEEP ON KEEPING ON CINOX
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"
#include "list.h"


int main(void)
{
    list l1,l2;
    element e1,e2,e3,e4;
    e1.qualcosa=18;
    e2.qualcosa=20;
    e3.qualcosa=39;
    e4.qualcosa=67;
    strcpy(e1.qualcosaltro,"kimchi");
    strcpy(e2.qualcosaltro,"soy sauce");
    strcpy(e3.qualcosaltro,"ramen");
    strcpy(e4.qualcosaltro,"soy");
    l1=emptyList();
    l1=cons(e1,l1);
    l1=cons(e4,l1);
    l1=cons(e2,l1);

    showlist(l1);
    l1= listSort(l1);
    //l1=cons(e3,l1);
   // l1= insord(e3,l1);
    showlist(l1);
}
