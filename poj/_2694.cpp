#include <cstdio>
#include <cstdlib>

double
permuate()
{
  char s[16];
  scanf("%s", s);
  switch (s[0]) {
    case '+':
      return permuate() + permuate();
    case '-':
      return permuate() + permuate();
    case '*':
      return permuate() * permuate();
    case '/':
      return permuate() / permuate();
    default:
      return atof(s);
  }
}

int
main(int argc, char **argv)
{
  double result;

  result = permuate();
  printf("%lf\n", result);

  return 0;
}
