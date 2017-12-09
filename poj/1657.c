#include <stdio.h>
#include <math.h>

int
main( int argc, char **argv )
{
  int nSamples, rDiff, cDiff;
  char s[3], d[3];

  scanf("%d", &nSamples);
  for( int i=0; i<nSamples; i++ ) {
    scanf("%s%s", s, d);
    rDiff = abs(s[0]-d[0]);
    cDiff = abs(s[1]-d[1]);

    if( rDiff==0 && cDiff==0 ) {
      printf("0 0 0 0\n");
      continue;
    }

    printf("%d ", (rDiff>cDiff)?rDiff:cDiff);
    printf("%d ", (rDiff==0||cDiff==0||rDiff==cDiff)?1:2);
    printf("%d ", (rDiff==0||cDiff==0)?1:2);
    if(abs(rDiff-cDiff)%2!=0) printf("Inf\n");
    else if(rDiff==cDiff) printf("1\n");
    else  printf("2\n");
  }

  return 0;
}
