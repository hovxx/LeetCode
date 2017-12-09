#include <cstdio>

int
f(int m, int n)
{
  if(n==1 || m==0)  return 1;
  if(n>m) return f(m,m);
  return f(m, n-1) + f(m-n, n);
}

int
main(int argc, char **argv)
{
  int k;

  scanf("%d", &k);
  for(int i=0; i<k; i++) {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n", f(m,n));
  }

  return 0;
}
