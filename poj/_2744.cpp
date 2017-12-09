#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string
str_reverse(string str)
{
  string rel = str;
  reverse(rel.begin(), rel.end());

  return rel;
}

vector<string>
find_substr(string str)
{
  vector<string> v;
  int len=str.size(), i, j;

  for(i=0; i<len; i++)
    for(j=i; j<len; j++)
      v.push_back(str.substr(i, j-i+1));

  return v;
}

int
match(vector<string> &v, string str)
{
  int i, len=v.size();
  string str_re = str_reverse(str);

  for(i=0; i<len; i++) {
    if(v[i].find(str)==string::npos && v[i].find(str_re)==string::npos) {
      return 0;
    }
  }

  return str.size();
}

string
find_shortest_str(vector<string> &v)
{
  int i, len=v.size();
  string rel = v[0];

  for(i=1; i<len; i++)
    if(v[i].size()<rel.size())
      rel = v[i];

  return rel;
}

int
main(int argc, char **argv)
{
  int nSamples, n, i, j;
  vector<string> v;

  cin >> nSamples;
  for(i=0; i<nSamples; i++) {
    int max = 0;
    string str;
    vector<string> sub_v;
    cin >> n;
    v.clear();
    for(j=0; j<n; j++) {
      cin >> str;
      v.push_back(str);
    }

    str = find_shortest_str(v);
    sub_v = find_substr(str);

    for(j=0; j<sub_v.size(); j++) {
      int t = match(v, sub_v[j]);
      if(t>max) max = t;
    }

    cout << max << endl;
  }

  return 0;
}
