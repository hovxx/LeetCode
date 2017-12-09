#include <cstdio>
#include <cstdlib>

char **p;
int W, H;

int
f(int x, int y)
{
  if(x<0||x>=W||y<0||y>=H)
    return 0;
  if(p[x][y]=='#')
    return 0;
  else {
    p[x][y] = '#';
    return f(x-1, y)+f(x+1, y)+f(x, y-1)+f(x, y+1);
  }
}

int
main(int argc, char **argv)
{
  int i, j;
  int x, y;

  scanf("%d %d", &W, &H);
  p = (char **)calloc(H, sizeof(char *));
  for(i=0; i<H; i++)
    p[i] = (char *)calloc(W, sizeof(char));

  for(i=0; i<H; i++) {
    for(j=0; j<W; j++) {
      scanf("%c", &p[i][j]);
      if(p[i][j]=='@') {
        x = i;
        y = j;
      }
    }
    printf("\n");
  }

  printf("%d\n", f(x, y));

  return 0;
}
