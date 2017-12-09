#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[26] = "22233344455566670778889990";
char number[10000][9], str[128];

int
compare(const void *str1, const void *str2)
{
  return (strcmp(str1, str2));
}

void
standard_string(int n)
{
  int j, k=0;

  for( j=0; str[j]!='\0'; j++ ) {
    if(str[j]=='-') continue;
    if(k==3)  number[n][k] = '-';
    if(str[j]>='A'&&str[j]<='Z')  number[n][k] = map[str[j]-'A'];
    if(str[j]>=2&&str[j]<=9)  number[n][k] = str[j];
    k ++;
  }
  number[n][k] = '\0';
}

int
main(int argc, char **argv)
{
  int nSamples, i, j;

  scanf("%d", &nSamples);
  for( i=0; i<nSamples; i++ ) {
    scanf("%d", str);
    standard_string(i);
  }

  qsort(number, nSamples, 9, compare);

  int flag = 1;
  while(i<nSamples) {
    j = i;
    i ++;
    while(i<nSamples&&strcmp(number[i], number[j])) i ++;
    if(i-j>1) {
      printf("%s %d\n", number[j], i-j);
      flag = 0;
    }
  }
  if(flag)
    printf("No Duplicate\n");

  return 0;
}
