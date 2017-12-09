#include <cstdio>
#include <cstring>

char str[7];
char result[7];
int used[7];
int L;

void
permulation(int n)
{
  if(n==L) {
    result[n] = '\0';
    printf("%s\n", result);
    return;
  }

  for(int i=0; i<L; i++) {
    if(!used[i]) {
      result[n] = str[i];
      used[i] = 1;
      permulation(n+1);
      used[i] = 0;
    }
  }
}

int
main(int argc, char **argv)
{
  scanf("%s", str);
  L = strlen(str);
  memset(used, 0, 7*sizeof(int));
  permulation(0);

  return 0;
}
