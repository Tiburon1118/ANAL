/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include "sorting.h"
#include "permutations.h"

/***************************************************/
/* Function: average_sorting_time Date: 30/09/2026 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms, int N, PTIME_AA ptime){

  if(!metodo|| n_perms <= 0 || N <= 0 || !ptime) return ERR;
  
  int i, ob_count;
  clock_t start, end;
  long total = 0;
  ptime->min_ob = 99999;
  ptime->max_ob = 0;

  int** perm = generate_permutations(n_perms, N);
  if(perm == NULL) return ERR;

  start = clock();
  if(start == (clock_t)-1) return ERR;

  for(i = 0; i < n_perms; i++){

    ob_count = metodo(perm[i], 0, N-1);
    total += ob_count;
    if(ob_count < ptime->min_ob){
      ptime->min_ob = ob_count;
    }
    if(ob_count > ptime->max_ob){
      ptime->max_ob = ob_count;
    }
    
  }
  end = clock();
  if(end == (clock_t)-1) return ERR;

  ptime->n_elems = n_perms;
  ptime->N = N;
  ptime->average_ob = total/n_perms;
  ptime->time = ((double)(end - start)) / CLOCKS_PER_SEC / n_perms;


  return OK;
}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms){
  
  PTIME_AA *ptime = NULL;
  int N=0, k;
  if(method == NULL || 1 > num_min || num_min > num_max || incr < 0 || n_perms <0){
    return ERR;
  }

  if(!(ptime = (PTIME_AA*)malloc(n_perms*sizeof(PTIME_AA)))){
    return ERR;
  }


  

  for(k=0; N < num_max; k++){
    N = num_min + k * incr;
    if(average_sorting_time(method, n_perms, N, ptime[k]) == ERR){
      free(ptime);
      return ERR;
    }
  }

  if(save_time_table(file, *ptime, n_perms) == ERR){
      free(ptime);
      return ERR;
    }

  return OK;
}


/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  /* your code */
}


