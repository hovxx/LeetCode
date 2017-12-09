#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main( int argc, char **argv )
{
  int L, M, x, y, *tree;
  int sum = 0;

  scanf("%d %d", &L, &M);
  tree = (int *)calloc(L+1, sizeof(int));
  memset(tree, 0, (L+1)*sizeof(int));
  for( int i=0; i<M; i++ ) {
    scanf("%d %d", &x, &y);
    for( int j=x; j<=y; j++ )
      tree[j] = 1;
  }
  for( int i=0; i<=L; i++ ) 
    if(tree[i]==1)
      sum ++;
  printf("%d\n", L+1-sum);

  free(tree);

  return 0;
}
