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

/*******************************************************/
/* Function: InsertSort    Date:23-09-26               */
/* Your comment                                        */
/*******************************************************/
int InsertSort(int* array, int ip, int iu) {

  int i, A, j;

  for(i = ip + 1; i < iu; i++){
      A = array[i];
      j = i-1;
      while (j >= ip && array[j] > A){
        array[j + 1] = array[j];
        j--;
      }
      array[j+1] = A;
  }

  return *array;
}


/***************************************************/
/* Function: SelectSort    Date:23-09-26           */
/* Your comment                                    */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{
  
  int flag = 1, i = iu;
  int aux = 0, j;
  
  while(flag == 1 && i >= ip + 1){
      flag = 0;
      for(j = ip; j < i - 1; j++){
        if(array[j] > array[j + 1]){
          aux = array[j];
          array[j + 1]= array[j]; 
          array[j] = aux;
          flag = 1;
        }
      }
      i--;
  }

  return *array;
}
