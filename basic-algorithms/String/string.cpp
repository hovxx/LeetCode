/* string algorithms */

#include "string.h"

#include <cstring>
#include <cstdio>


/* reverse string */
void
reverse_string(string &str)
{
  for(int i=0; i<str.size()/2; i++)
    swap(str[i], str[str.size()-i-1]);
}

/* reverse words in string */
void
reverse_words_in_string(string &str)
{
  reverse(str.begin(), str.end());
  int start=0;
  for(int i=0; i<str.size(); i++) {
    if(str[i]==' ') {
      reverse(str.begin()+start, str.begin()+i);
      start = i + 1;
      continue;
    }
    if(i==str.size()-1)
      reverse(str.begin()+start, str.end());
  }
}

/* move blanks in string to tail */
void
move_blank(string &str)
{
  int blanks = 0;
  for(int i=0; i<str.size(); i++) {
    if(str[i]!=' ')
      str[i-blanks] = str[i];
    else
      blanks ++;
  }
  for(int i=str.size()-1; i>=str.size()-blanks; i--)
    str[i] = ' ';
}

/* split string by blank */
vector<string>
split(string &str)
{
  vector<string> ans;
  string s = "";

  for(int i=0; i<str.size(); i++) {
    if(str[i]!=' ')
      s.append(1, str[i]);
    else {
      ans.push_back(s);
      s = "";
    }
  }
  ans.push_back(s);

  return ans;
}

/* split string by blank, simple implemented in C++ */
void
split_c(char *s)
{
  int size = strlen(s) + 1;
  char word[size];
  int flag = 0;

  memset(word, 0, size*sizeof(char));
  for(int i=0; s[i]!='\0'; i++) {
    if(s[i]!=' ')
      word[flag++] = s[i];
    else {
      word[flag] = '\0';
      printf("%s\n", word);
      flag = 0;
    }
  }
  printf("%s\n", word);
}

/* permute all orders of string */
static void
permute_recur(string &str, int start, vector<string> &ans)
{
  if(start>=str.size()) {
    ans.push_back(str);
    return;
  }
  for(int i=start; i<str.size(); i++) {
    swap(str[i], str[start]);
    permute_recur(str, start+1, ans);
    swap(str[i], str[start]);
  }
}

vector<string>
permute(string &str)
{
  vector<string> ans;
  if(str.size()==0)
    return ans;
  sort(str.begin(), str.end());
  permute_recur(str, 0, ans);
  return ans;
}

/* convert string integer */
int
string_to_int(const char *s)
{
  return 0;
}

/* conjecture whether a string is palindrome */
int
is_palindrome(string &str)
{
  int i=0, j=str.size()-1;

  while(i<j) {
    if(str[i]!=str[j])
      return 0;
    i ++;
    j --;
  }
  return 1;
}

/* match all patterns in a string */
vector<int>
match(string &str, string &pattern)
{
  vector<int> ans;
  int str_len=str.size(), pattern_len=pattern.size();

  for(int i=0; i<str_len-pattern_len+1; i++) {
    if(str[i]==pattern[0]) {
      int flag = 1;
      for(int j=i+1, k=1; k<pattern_len; j++, k++) {
        if(str[j]!=pattern[k]) {
          flag = 0;
          break;
        }
      }
      if(flag==1)
        ans.push_back(i);
    }
  }

  return ans;
}

/* add two binary */
string
add_binary(string a, string b)
{
  string ans = "";
  int flag = 0;
  int i=a.size()-1, j=b.size()-1;

  while(i>=0 || j>=0 || flag==1) {
    flag += (i>=0)?(a[i--]-'0'):0;
    flag += (j>=0)?(b[j--]-'0'):0;
    ans = flag%2+'0' + ans;
    flag /= 2;
  }

  return ans;
}
