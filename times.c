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
#include  "permutations.h"

/***************************************************/
/* Function: average_sorting_time Date: 30/09/2026 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms, int N, PTIME_AA ptime){

  if(!metodo|| n_perms < 0 || N < 0 || !ptime) return ERR;
  
  int i;

  int perm = generate_permutatios(n_perms, N);
  if(perm == NULL) return ERR;

  long sum = 0;
  ptime->min_ob = 0;
  ptime->max_ob = 0;

  for(i = 0; i < n_perms; i++){
    int ob_count = metodo(perm[i], 0, N-1);
    sum += ob_count;
    ptime->min_ob = ob_count;
    ptime->max_ob = ob_count;
  }




}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max, int incr, int n_perms){
  /* Your code */
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


