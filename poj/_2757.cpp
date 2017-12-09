#include <cstdio>

int N;
int x[1024];
int l[1024];

int
main(int argc, char **argv)
{
  int i, j, n;

  scanf("%d", &N);
  for(i=0; i<N; i++) {
    scanf("%d", &n);
    x[i] = n;
  }

  l[0] = 1;
  for(i=1; i<N; i++) {
    int max = 0;
    for(j=0; j<i; j++) {
      if(x[j]<x[i] && l[j]>max) max = l[j];
    }
    l[i] = max + 1;
  }

  int max = l[0];
  for(i=1; i<N; i++) {
    if(l[i]>max)  max = l[i];
  }
  printf("%d\n", max);

  return 0;
}
