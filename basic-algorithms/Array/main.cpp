/* main process */

#include "array.h"

#include <iostream>


int
main(int argc, char **argv)
{
  int arr[10] = {0,12,-4,-23,13,33,1,-2,-12,9};
  vector<int> vec(&arr[0], &arr[10]);
  // sort(vec.begin(), vec.end());

  // vector<int> ans = find_k_numbers(vec, 4);

  // int len = remove_duplicate_numbers(arr, 10);

  // vector<int> ans = find_numbers(vec, 68);

  // vector<int> ans = find_numbers_1(vec, 11);

  // int ans = max_sub_array(vec, res);

  cout << find_bin(10) << endl;

  return 0;
}
