/* sort algorithms */


#include "sort.h"

/* insert sort */
void
insert_sort(double *arr, int size)
{
  int i, j;

  for(i=1; i<size; i++) {
    double t = arr[i];
    j = i-1;
    while(arr[j]>t && j>=0) {
      arr[j+1] = arr[j];
      j --;
    }
    arr[j+1] = t;
  }
}

/* bubble sort */
void
bubble_sort(double *arr, int size)
{
  int i, j;

  for(i=0; i<size-1; i++) {
    for(j=size-1; j>i; j--) {
      if(arr[j]<arr[j-1]) {
        double t = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = t;
      }
    }
  }
}

/* selection sort */
void
selection_sort(double *arr, int size)
{
  int i, j, min;

  for(i=0; i<size; i++) {
    min = i;
    for(j=i+1; j<size; j++) {
      if(arr[j]<arr[min])
        min = j;
    }
    double t = arr[i];
    arr[i] = arr[min];
    arr[min] = t;
  }
}

/* quick sort */
void
quick_sort(double *arr, int start, int end)
{
  if(start>end) return;

  int i=start, j=end;
  double x=arr[start];

  while(i<j) {
    while(arr[j]>x&&i<j)  j --;
    if(i<j) arr[i++] = arr[j];
    while(arr[i]<x&&i<j)  i ++;
    if(i<j) arr[j--] = arr[i];
  }
  arr[i] = x;

  quick_sort(arr, start, i-1);
  quick_sort(arr, i+1, end);
}

/* merge sort */
void
merge_sort(double *arr, int start, int end)
{
  if(start>=end) return;

  int mid = (start+end)/2;
  int l_num=mid-start+1, r_num=end-mid;
  double *l_arr = new double[l_num];
  double *r_arr = new double[r_num];
  int l=0, r=0, i;

  merge_sort(arr, start, mid);
  merge_sort(arr, mid+1, end);

  for(i=start; i<=end; i++) {
    if(i<=mid)  l_arr[l++] = arr[i];
    if(i>mid)   r_arr[r++] = arr[i];
  }

  l = r = 0;
  i = start;
  while(l<l_num && r<r_num) {
    if(l_arr[l]<r_arr[r]) arr[i++] = l_arr[l++];
    else  arr[i++] = r_arr[r++];
  }
  while(l<l_num)
    arr[i++] = l_arr[l++];
  while(r<r_num)
    arr[i++] = r_arr[r++];

  delete[] l_arr;
  delete[] r_arr;
}

/* heap sort */
static void
adjust_heap(double *arr, int head, int size)
{
  int child;
  for(; 2*head+1<size; head=child) {
    child = 2*head+1;
    if(child+1<size && arr[child+1]>arr[child]) ++child;
    if(arr[head]<arr[child]) {
      double t = arr[child];
      arr[child] = arr[head];
      arr[head] = t;
    }
    else  break;
  }
}

void
heap_sort(double *arr, int size)
{
  for(int i=size-1; i>=0; i--)
    adjust_heap(arr, i, size);

  for(int i=size-1; i>0; i--) {
    double t = arr[i];
    arr[i] = arr[0];
    arr[0] = t;
    adjust_heap(arr, 0, i-1);
  }
}
