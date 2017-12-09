/* array algorithms */

#ifndef __ARRAY_H
#define __ARRAY_H

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_k_numbers(vector<int> &vec, int k);

int find_no_duplicate_number(int A[], int n);
int remove_duplicate_numbers(int A[], int n);

vector<int> find_numbers(vector<int> &vec, int sum);
vector<int> find_numbers_1(vector<int> &vec, int sum);

int max_sub_array(vector<int> &vec, vector<int> &ans);

int find_bin(int x);

#endif
