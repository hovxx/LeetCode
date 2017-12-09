/* array algorithms */

#include "array.h"


/* find k smallest number */
static void
adjust_heap(vector<int> &vec, int end)
{
  for(int i=end; i>=0; i--) {
    if(2*i+1<=end) {
      int min=2*i+1;
      if(2*i+2<=end && vec[2*i+2]<vec[min]) min = 2*i+2;
      if(vec[min]<vec[i]) swap(vec[min], vec[i]);
    }
  }
}

vector<int>
find_k_numbers(vector<int> &vec, int k)
{
  int size = vec.size();
  vector<int> ans;

  if(size<k)
    return ans;

  for(int i=0; i<k; i++) {
    adjust_heap(vec, size-i-1);
    ans.push_back(vec[0]);
    swap(vec[0], vec[size-i-1]);
  }

  return ans;
}

/* remove duplicate numbers in an array */
int
remove_duplicate_numbers(int A[], int n)
{
  int cur = A[0], dup = 0;

  for(int i=1; i<n; i++) {
    if(A[i]==cur)
      dup ++;
    else
      cur = A[i];
    A[i-dup] = A[i];
  }

  return n-dup;
}

/* find two numbers which equal to sum */
vector<int>
find_numbers(vector<int> &vec, int sum)
{
  int i=0, j=vec.size()-1;
  vector<int> ans;

  while(i<j) {
    int t = vec[i] + vec[j];
    if(t<sum) i ++;
    else if(t>sum) j --;
    else {
      ans.push_back(i);
      ans.push_back(j);
      break;
    }
  }

  return ans;
}

/* find three numbers which equal to sum */
vector<int>
find_numbers_1(vector<int> &vec, int sum)
{
  vector<int> ans;

  if(vec.size()<3)
    return ans;
  for(int i=0; i<vec.size()-2; i++) {
    int temp = sum-vec[i];
    int j=i+1, k=vec.size()-1;
    while(j<k) {
      int s=vec[j]+vec[k];
      if(s<temp)  j ++;
      else if(s>temp) k --;
      else {
        ans.push_back(vec[i]);
        ans.push_back(vec[j]);
        ans.push_back(vec[k]);
        return ans;
      }
    }
  }
  return ans;
}

/* find max continuous sequence */
int
max_sub_array(vector<int> &vec, vector<int> &res)
{
  int sum=0,temp=0,start=0,new_start=0,end=0;

  for(int i=0; i<vec.size(); i++) {
    if(temp<0) {
      temp = vec[i];
      new_start = i;
    }
    else
      temp += vec[i];
    if(sum<temp) {
      sum = temp;
      start = new_start;
      end = i;
    }
  }

  res.push_back(start);
  res.push_back(end);

  return sum;
}

/* find 1 numbers in x */
int
find_bin(int x)
{
  int count = 0;

  while(x) {
    count ++;
    x = x&(x-1);
  }
  return count;
}
