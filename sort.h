/*
 * sort.h contiene le dichiarazioni delle funzioni
 * di sort dei vettori per adattare queste funzioni al
 * tipo del vettore basta modificare il typedef
 */

#ifndef CREAZIONE_TEST_LIBRERIE_SORT_H
#define CREAZIONE_TEST_LIBRERIE_SORT_H

#include <stdlib.h> //per malloc

typedef int type;   //sostituire con il tipo del vettore da ordinare

void change(type* a, type* b);

void naiveSort(type v[], int dim);

void bubbleSort(type v[], int dim);

void insertSort(type v[], int dim);

void mergeSort(type v[], int dim);

void quickSort(type v[], int dim);

#endif //CREAZIONE_TEST_LIBRERIE_SORT_H
