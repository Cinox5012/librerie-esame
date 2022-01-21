/*
 * in element.h avviene la definizione del tipo element, ovverociò il tipo di dato stesso della list
 * il tipo list verrà definito in list.h
 * qui vengono inoltre definiti il tipo boolean e alcune funzioni boolean
 *  KEEP ON KEEPING ON CINOX
*/


#ifndef CREAZIONE_TEST_LIBRERIE_ELEMENT_H
#define CREAZIONE_TEST_LIBRERIE_ELEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG1 20

//se l'elemento è un intero o un tipo definito già in c
//la cosa più rapida è usare typedef per definirlo,
//per esempio:

//typedef int element;

//nel caso element sia una struttura la cosa è simile
//si userà typedef per dare alla struttura il nome element
//a scopo di testing questo caso è qui commentato


  typedef struct nome_struct{
  int qualcosa;
  char qualcosaltro[LONG1];
  }element;

//definisci qui eventuali altre strutture

//ora definiamo boolean
//la definizione di boolean è necessaria per list.h
//in paritcolare per empty();

typedef enum {false,true}boolean;

//ecco ora le funzioni boolean che possono servire in list.c
//in element.c è presente una versione di queste funzioni per
//element intero o per element struct ;-)

boolean isEqual(element e1,element e2);
boolean isLess(element e1, element e2);
boolean isGreater(element e1, element e2);
element getElement();
void showElement(element e1);

#endif //CREAZIONE_TEST_LIBRERIE_ELEMENT_H
