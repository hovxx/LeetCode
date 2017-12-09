#include <cstdio>

int
f(int x, int y)
{
  if(x==y)  return x;
  if(x>y) return f(x/2, y);
  else  return f(x, y/2);
}

int
main(int argc, char **argv)
{
  int x, y;

  scanf("%d %d", &x, &y);
  printf("%d\n", f(x,y));

  return 0;
}
