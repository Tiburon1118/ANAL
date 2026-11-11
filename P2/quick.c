#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quick.h"

// funcion auxiliar para swaps
static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int QuickSort_min(int* array, int ip, int iu) {
    
    if (!array || ip < 0) return ERR;
    if (ip >= iu) return 0;

    int pos;
    int count = partition(array, ip, iu, &pos, pivot_min);
    if (count == ERR) return ERR;

    if (ip < pos - 1) {
        int qs_l = QuickSort_min(array, ip, pos - 1);
        if (qs_l == ERR) return ERR;
        count += qs_l;
    }

    if (pos + 1 < iu) {
        int qs_r = QuickSort_min(array, pos + 1, iu);
        if (qs_r == ERR) return ERR;
        count += qs_r;
    }

    return count;
}

int partition(int* array, int ip, int iu, int* pos, pfunc_pivot pivot) {
    
    if (!array || ip < 0 || ip > iu || !pos || !pivot) return ERR;

    int pivot_aux;
    int aux = pivot(array, ip, iu, &pivot_aux);
    if (aux == ERR) return ERR;

    swap(&array[ip], &array[pivot_aux]);
    int k = array[ip];
    int m = ip;

    for (int i = ip + 1; i <= iu; i++) {
        aux++;
        if (array[i] < k) {
            m++;
            swap(&array[i], &array[m]);
        }
    }

    swap(&array[ip], &array[m]);
    *pos = m;

    return aux;
}

int pivot_min(int* array, int ip, int iu, int* pos){

    if(!array || ip < 0 || ip > iu || !pos) return ERR;

    *pos = ip;

    return 0;
}
