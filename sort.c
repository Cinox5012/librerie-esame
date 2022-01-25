/*
 * implementazione delle funzioni di sort
 * per ogni funzione è indicato dove modificare il segno
 * per ribaltare l'ordinamento
 */

#include "sort.h"

void change(type* a, type* b){
    type tmp=*a;
    *a=*b;
    *b=tmp;
}

void naiveSort(type v[], int n) {
    while (n > 1) {
        int posMax = 0;
        for (int i = 1; i < n; i++)
            if (v[posMax]<v[i]) //modificare qui ordine
                posMax = i;

        if (posMax < n - 1)
            change(&v[posMax], &v[n - 1]);

        n--;
    }
}

void bubbleSort(type v[], int n) {
    int i, ordinato = 0;
    while (n > 1 && !ordinato) {
        ordinato = 1;
        for (i = 0; i < n - 1; i++)
            if (v[i + 1]<v[i]) {    //modificare qui ordine
                change(&v[i], &v[i + 1]);
                ordinato = 0;
            }
        n--;
    }
}

void insertSort(type v[], int n) {
    for (int k = 1; k < n; k++) {
        int i = k - 1;
        type x = v[k];
        while (i >= 0 && (x<v[i])) {    //modificare qui ordine
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
}

void merge(type v[], int i1, int i2, int fine, type vout[]) {
    int i = i1, j = i2, k = i1;

    while (i <= i2 - 1 && j <= fine) {
        if (v[i]<v[j])                  //modificare qui ordine
            vout[k++] = v[i++];
        else
            vout[k++] = v[j++];
    }
    while (i <= i2 - 1)
        vout[k++] = v[i++];
    while (j <= fine)
        vout[k++] = v[j++];

    for (i = i1; i <= fine; i++)
        v[i] = vout[i];
}

void mergeSortC(type v[], int first, int last, type vout[]) {
    int mid;
    if (first < last) {
        mid = (last + first) / 2;
        mergeSortC(v, first, mid, vout);
        mergeSortC(v, mid + 1, last, vout);
        merge(v, first, mid + 1, last, vout);
    }
}

void mergeSort(type v[], int n) {
    type* vout = (type*)malloc(sizeof(type) * n);
    if (vout != NULL) {
        mergeSortC(v, 0, n - 1, vout);
        free(vout);
    }
    else exit(1);
}

void quickSortR(type a[], int first, int last) {
    int i, j, iPivot;
    type pivot;
    if (first < last) {
        i = first;
        j = iPivot = last;
        pivot = a[iPivot];

        do {
            while (i < j && (a[i]<pivot) )
                i++;
            while (j > i && (a[j]<pivot))
                j--;
            if (i < j)
                change(&a[i], &a[j]);
        } while (i < j);

        if (i != iPivot && (a[i]<a[iPivot])) {
            change(&a[i], &a[iPivot]);
            iPivot = i;
        }

        if (first < iPivot - 1)
            quickSortR(a, first, iPivot - 1);
        if (iPivot + 1 < last)
            quickSortR(a, iPivot + 1, last);
    }
}

void quickSort(type a[], int dim) {
    quickSortR(a, 0, dim - 1);
}