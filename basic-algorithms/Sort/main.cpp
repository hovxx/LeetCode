/* main process */

#include "sort.h"

#include <cstdio>
#include <cstdlib>

#define ARR_SIZE 1024

double arr[ARR_SIZE];

void
init_arr()
{
  for(int i=0; i<ARR_SIZE; i++)
    arr[i] = (double)rand()/RAND_MAX-0.5;
}

int
main(int argc, char **argv)
{
  init_arr();

  // insert_sort(arr, ARR_SIZE);
  // bubble_sort(arr, ARR_SIZE);
  // selection_sort(arr, ARR_SIZE);
  // quick_sort(arr, 0, ARR_SIZE-1);
  // merge_sort(arr, 0, ARR_SIZE-1);
  heap_sort(arr, ARR_SIZE);

  for(int i=0; i<ARR_SIZE; i++)
    printf("%lf ", arr[i]);

  return 0;
}
