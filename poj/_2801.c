#include <stdio.h>
#include <string.h>

int
main( int argc, char **argv )
{
  int N, M, P;
  int i, j;
  char vob[26];

  memset(vob, 0, 26*sizeof(char));
  scanf("%d %d %d", &N, &M, &P);

  for( i=0; i<N; i++ ) {
    char str[M+1];
    scanf("%s", str);
    for( j=0; j<M; j++)
      vob[str[j]-'A'] ++;
  }

  for( i=0; i<P; i++ ) {
    char str[256];
    scanf("%s", str);
    for( j=0; str[j]!='\0'; j++ )
      vob[str[j]-'A'] --;
  }

  for( i=0; i<26; i++ ) {
    if(vob[i]!=0) {
      for( j=0; j<vob[i]; j++ )
        printf("%c", i+'A');
    }
  }
  printf("\n");

  return 0;
}
