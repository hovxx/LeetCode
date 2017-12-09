/* string algorithms */

#ifndef __STRING_H
#define __STRING_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reverse_string(string &str);
void reverse_words_in_string(string &str);

void move_blank(string &str);
vector<string> split(string &str);
void split_c(char *s);

vector<string> permute(string &str);

int string_to_int(const char *s);

int is_palindrome(string &str);

vector<int> match(string &str, string &pattern);

string add_binary(string a, string b);

#endif
