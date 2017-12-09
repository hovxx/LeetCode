#include <cstdio>
#include <cstring>

#define MAX_NUM 256
char s1[MAX_NUM], s2[MAX_NUM];
int result[MAX_NUM][MAX_NUM];
int L1, L2;

int
main(int argc, char **argv)
{
  int i, j;

  while(1) {
    scanf("%s %s", s1, s2);
    L1 = strlen(s1);
    L2 = strlen(s2);

    for(i=0; i<=L1; i++)  result[i][0] = 0;
    for(j=0; j<=L2; j++)  result[0][j] = 0;
    for(i=1; i<=L1; i++) {
      for(j=1; j<=L2; j++) {
        if(s1[i-1]==s2[j-1])
          result[i][j] = result[i-1][j-1] + 1;
        else
          result[i][j] = (result[i-1][j]>result[i][j-1]) ? result[i-1][j] : result[i][j-1];
      }
    }

    printf("%d\n", result[L1][L2]);
  }

  return 0;
}
