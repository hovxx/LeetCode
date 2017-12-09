#include <cstdio>
#include <cstring>

#define MAX_NUM 300
int aLoop[MAX_NUM+10];

int
main(int argc, char **argv)
{
  int n, m, i;

  while(1) {
    scanf("%d %d", &n, &m);
    if(n==0 || m==0)  break;

    for(i=0; i<n; i++)
      aLoop[i] = i+1;

    int nPtr = 0;
    for(i=0; i<n; i++) {
      int nCounter = 0;
      while(nCounter<m) {
        while(aLoop[nPtr]==0)
          nPtr = (nPtr+1)%n;
        nCounter ++;
        nPtr = (nPtr+1)%n;
      }
      nPtr --;
      if(nPtr<0)  nPtr = n-1;
      if(i==n-1)  printf("%d\n", aLoop[nPtr]);
      aLoop[nPtr] = 0;
    }
  }

  return 0;
}
