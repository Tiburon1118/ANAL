#ifndef QUICK_H
#define QUICK_H

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

typedef int (*pfunc_pivot)(int*, int, int, int*);

int QuickSort_min(int* array, int ip, int iu);
int partition(int* array, int ip, int iu, int* pos, pfunc_pivot pivot);
int pivot_min(int* array, int ip, int iu, int* pos);

int QuickSort_mean(int* array, int ip, int iu);
int pivot_mean(int* array, int ip, int iu, int* pos);

int pivot_median(int* array, int ip, int iu, int* pos);
int QuickSort_median(int* array, int ip, int iu);

#endif
