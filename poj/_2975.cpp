#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char
invert(char ch)
{
  if(ch-5>=65)  return (ch-5);
  else  return (ch+21);
}

int
main(int argc, char **argv)
{
  while(1) {
    string password;
    gets(password);
    if(password=="ENDOFINPUT")  break;
    for(int i=0; i<password.size(); i++)
      if(password[i]>='A' && password[i]<='Z')
        password[i] = invert(password[i]);
    cout << password << endl;
  }

  return 0;
}
