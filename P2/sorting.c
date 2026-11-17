/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorting.h"

/***************************************************/
/* Function: InsertSort Date: 23/09/26             */
/* Authors: Jorge Caceres                          */
/*                                                 */
/* Routine that sorts an array segment using the   */
/* insertion sort algorithm and counts the number  */
/* of basic operation (OB) executions              */
/*                                                 */
/* Input:                                          */
/* int* array: array to be sorted                  */
/* int ip: starting index of the segment           */
/* int iu: ending index of the segment             */
/* Output:                                         */
/* int: total OB executions or ERR in case of error*/
/***************************************************/
int InsertSort(int* array, int ip, int iu) {

  int i, A, j;
  int count = 0;

  if(!array || ip < 0 || iu < 0) return ERR;

  if(ip == iu) return count;

  for(i = ip + 1; i <= iu; i++){
      A = array[i];
      j = i-1;
       while (j >= ip) {
          count++;
          
          if (array[j] > A) {
              array[j + 1] = array[j];
              j--;
          } else {
            
              break; 
          }
      }
      array[j+1] = A;
  }

  return count;
}


/***************************************************/
/* Function: BubbleSort   Date: 23/09/26           */
/* Authors: Jorge Caceres                          */
/*                                                 */
/* Routine that sorts an array segment using the   */
/* optimized bubble sort algorithm (with early     */
/* stop flag) and counts the number of basic       */
/* operation (OB) executions                       */
/*                                                 */
/* Input:                                          */
/* int* array: array to be sorted                  */
/* int ip: starting index of the segment           */
/* int iu: ending index of the segment             */
/* Output:                                         */
/* int: total OB executions or ERR in case of error*/
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{
  
  int flag = 1, i = iu;
  int aux = 0, j;
  int count = 0;

  if(!array || ip < 0 || iu < 0) return ERR;

  while(flag == 1 && i >= ip + 1){
      flag = 0;
      for(j = ip; j < i - 1; j++){
        count++;
        if(array[j] > array[j + 1]){
          aux = array[j];
          array[j + 1]= array[j]; 
          array[j] = aux;
          flag = 1;
        }
      }
      i--;
  }

  return count;
}
/***************************************************/
/* Function: BubbleSort   Date: 23/09/26           */
/* Authors: Jorge Caceres                          */
/*                                                 */
/* Routine that sorts an array segment using the   */
/* optimized bubble sort algorithm (with early     */
/* stop flag) and counts the number of basic       */
/* operation (OB) executions                       */
/*                                                 */
/* Input:                                          */
/* int* array: array to be sorted                  */
/* int ip: starting index of the segment           */
/* int iu: ending index of the segment             */
/* Output:                                         */
/* int: total OB executions or ERR in case of error*/
/***************************************************/
int MergeSort(int* array, int ip, int iu){
  int im, res;
  int total = 0; /* 1. Inicializar a 0 */

  if(array == NULL || ip > iu || ip < 0 || iu < 0){
    return ERR;
  }

  if(ip == iu){
    return 0; 
  }

  im = (ip + iu) / 2;

  res = MergeSort(array, ip, im);
  if(res == ERR) return ERR;
  total += res;

  res = MergeSort(array, im + 1, iu);
  if(res == ERR) return ERR;
  total += res;

  res = merge(array, ip, iu, im); 
  if(res == ERR) return ERR;
  
  return total + res;
}

int merge(int* array, int ip, int iu, int im){
  int i, j, k, size;
  int total = 0; /* 1. Inicializar a 0 */
  int *aux = NULL;

  if(array == NULL || ip < 0 || iu < 0 || ip > iu || im < ip || im > iu){
    return ERR;
  }

  if(ip == iu){
    return 0;
  }

  size = iu - ip + 1;
  if(!(aux = (int*)malloc(size * sizeof(int)))){
    fprintf(stderr, "Error: no se pudo reservar memoria en merge\n");
    return ERR;
  }

  i = ip;
  j = im + 1;
  k = 0; 

  while (i <= im && j <= iu){
    total++;
    if(array[i] < array[j]){
      aux[k] = array[i];
      i++;
    } else {
      aux[k] = array[j];
      j++;
    }
    k++;
  }

  if(i > im){
    while(j <= iu){
      aux[k] = array[j];
      j++;
      k++;
    }
  } else if(j > iu){
    while(i <= im){ 
      aux[k] = array[i];
      i++;
      k++;
    }
  }

  for(i = ip; i <= iu; i++){
    array[i] = aux[i - ip];
  }

  free(aux);
  return total;
}

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
        qs_l = QuickSort_median(array, ip, pos - 1);
        if (qs_l == ERR) return ERR;
        count += qs_l;
    }

    if (pos + 1 < iu) {
        qs_r = QuickSort_median(array, pos + 1, iu);
        if (qs_r == ERR) return ERR;
        count += qs_r;
    }

    return count;

}