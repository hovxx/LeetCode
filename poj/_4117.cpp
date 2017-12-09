#include <iostream>

using namespace std;


int
f(int m, int i)
{
  if(m==0)  return 1;
  if(i==0)  return 0;
  if(i<=m)  return f(m-i, i)+f(m, i-1);
  if(i>m) return f(m,i-1);
}

int
main(int argc, char **argv)
{
  int n;

  while(cin>>n) {
    if(n<=0)  break;
    cout << f(n, n) << endl;
  }

  return 0;
}
