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
  int im, total,res;

  if(array == NULL || ip > iu || ip < 0 || iu < 0){
    return ERR;
  }

  if(ip == iu){
    return OK;
  }

  im = (ip+iu)/2;

  res = MergeSort(array, ip, im);
  if(res == ERR) return ERR;
  total += res;

  res = MergeSort(array, im + 1, iu);
  if(res == ERR) return ERR;
  total += res;

  res = merge(array, ip, im, iu);
  if(res == ERR) return ERR;
  
  return total + res;
}


int merge(int* array, int ip, int iu, int im){
  
  int i,j,k,size,total;
  int *aux = NULL;

  if(array == NULL || ip > iu || ip < 0 || iu  < 0){
    return ERR;
  }

  if(ip == iu){
    return 0;
  }
  size = iu-ip+1;
  if(!(aux = (int*)malloc(size*sizeof(int)))){
    return ERR;
  }

  i= ip;
  j=im+1;
  k=ip; 

  while (i<=im && j<= iu){
    if(array[i]<array[j]){
      aux[k] = array[i];
      i++;
    }else{
      aux[k] = array[j];
      j++;
    }
    k++;
    total++;
  }
  if(i>im){
    while(j<= iu){
      aux[k] = array[j];
      j++;
      k++;
    }
  }else if(j>iu){
    while(i<= iu){
      aux[k] = array[i];
      i++;
      k++;
    }
  }

  for(i=ip; i< iu; i++){
    array[i] = aux[i];
  }

  free(aux);
  return total;
}