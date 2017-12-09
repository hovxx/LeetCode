#include <cstdio>
#include <cstring>

int result[92][8];
int used[8];
int line;

void
permulate(int n)
{
  int i, j;

  if(n==8) {
    for(i=0; i<8; i++)
      result[line][i] = used[i]+1;
    line ++;
    return;
  }

  for(i=0; i<8; i++) {
    for(j=0; j<n; j++) {
      if(used[j]==i || n-j==used[j]-i || n-j==i-used[j])
        break;
    }
    if(j==n) {
      used[n] = i;
      permulate(n+1);
    }
  }
}

int
main(int argc, char **argv)
{
  memset(used, 0, 8*sizeof(int));
  line = 0;
  permulate(0);

  int nSamples;

  scanf("%d", &nSamples);
  for( int i=0; i<nSamples; i++ ) {
    int n;
    scanf("%d", &n);
    for( int j=0; j<8; j++ )
      printf("%d", result[n-1][j]);
    printf("\n");
  }

  return 0;
}
