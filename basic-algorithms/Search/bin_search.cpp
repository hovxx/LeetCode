/* binary search */

#include "bin_search.h"

int
find(std::vector<int> &arr, int x)
{
  int low=0, high=arr.size()-1;

  while(low<high) {
    int mid = (low+high)/2;
    if(arr[mid]>x)  high = mid - 1;
    else if(arr[mid]<x) low = mid + 1;
    else  return mid;
  }

  return -1;
}

std::vector<int>
find_k_sum(std::vector<int> &arr, int sum)
{
  std::vector<int> ans;
  int low=0, high=arr.size();

  while(low<high) {
    int t = arr[low] + arr[high];
    if(t<sum) low ++;
    else if(t>sum)  high --;
    else {
      ans.push_back(low);
      ans.push_back(high);
      break;
    }
  }

  return ans;
}
