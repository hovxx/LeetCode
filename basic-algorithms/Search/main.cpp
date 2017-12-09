/* main process */

#include "bin_search.h"

#include <cstdio>

int arr[] = {1,3,5,7,9,11,13,15,17,19,21};

int
main(int argc, char **argv)
{
  int L = sizeof(arr) / sizeof(int);
  std::vector<int> v(&arr[0], &arr[L]);

  // printf("%d\n", find(arr, 34));
  // printf("%d\n", find(arr, 45));

  std::vector<int> ans = find_k_sum(v, 24);
  if(ans.size()!=0) printf("%d %d\n", ans[0], ans[1]);

  return 0;
}
