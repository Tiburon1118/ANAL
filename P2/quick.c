#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quick.h"

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int QuickSort_min(int* array, int ip, int iu) {
    
    int pos;
    int count;
    int qs_l, qs_r;

    if (!array || ip < 0) return ERR;
    if (ip >= iu) return 0;

    count = partition(array, ip, iu, &pos, pivot_min);
    if (count == ERR) return ERR;

    if (ip < pos - 1) {
        qs_l = QuickSort_min(array, ip, pos - 1);
        if (qs_l == ERR) return ERR;
        count += qs_l;
    }

    if (pos + 1 < iu) {
        qs_r = QuickSort_min(array, pos + 1, iu);
        if (qs_r == ERR) return ERR;
        count += qs_r;
    }

    return count;
}

int partition(int* array, int ip, int iu, int* pos, pfunc_pivot pivot) {

    int pivot_aux;
    int aux;
    int i, k, m;

    if (!array || ip < 0 || ip > iu || !pos || !pivot) return ERR;

    aux = pivot(array, ip, iu, &pivot_aux);
    if (aux == ERR) return ERR;

    swap(&array[ip], &array[pivot_aux]);
    k = array[ip];
    m = ip;

    for (i = ip + 1; i <= iu; i++) {
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

int QuickSort_mean(int* array, int ip, int iu){

    int pos;
    int count;
    int qs_l, qs_r;

    if (!array || ip < 0) return ERR;
    if (ip >= iu) return 0;

    count = partition(array, ip, iu, &pos, pivot_mean);
    if (count == ERR) return ERR;

    if (ip < pos - 1) {
        qs_l = QuickSort_mean(array, ip, pos - 1);
        if (qs_l == ERR) return ERR;
        count += qs_l;
    }

    if (pos + 1 < iu) {
        qs_r = QuickSort_mean(array, pos + 1, iu);
        if (qs_r == ERR) return ERR;
        count += qs_r;
    }

    return count;

}

int pivot_mean(int* array, int ip, int iu, int* pos) {
    
    if (!array || ip < 0 || ip > iu || !pos) return ERR;

    *pos = ip + (iu - ip) / 2;

    return 0;
}

int pivot_median(int* array, int ip, int iu, int* pos) {
    int im;

    if (!array || ip < 0 || ip > iu || !pos) return ERR;

    im = ip + (iu - ip) / 2;

    if (array[ip] < array[im]) {
        if (array[im] < array[iu]) {
            *pos = im;
            return 2;
        } else if (array[ip] < array[iu]) {
            *pos = iu;
            return 3;
        } else {
            *pos = ip;
            return 3;
        }
    } else {
        if (array[ip] < array[iu]) {
            *pos = ip;
            return 2;
        } else if (array[im] < array[iu]) {
            *pos = iu;
            return 3;
        } else {
            *pos = im;
            return 3;
        }
    }
}

int QuickSort_median(int* array, int ip, int iu){

    int pos;
    int count;
    int qs_l, qs_r;

    if (!array || ip < 0) return ERR;
    if (ip >= iu) return 0;

    count = partition(array, ip, iu, &pos, pivot_median);
    if (count == ERR) return ERR;

    if (ip < pos - 1) {
        qs_l = QuickSort_mean(array, ip, pos - 1);
        if (qs_l == ERR) return ERR;
        count += qs_l;
    }

    if (pos + 1 < iu) {
        qs_r = QuickSort_mean(array, pos + 1, iu);
        if (qs_r == ERR) return ERR;
        count += qs_r;
    }

    return count;

}
