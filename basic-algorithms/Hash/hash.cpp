/* hash table */

#include "hash.h"

#include <cstdlib>
#include <iostream>

struct hash_node *
create_hash_table(int size)
{
  struct hash_node *hash_table = (struct hash_node *)calloc(size, sizeof(struct hash_node));

  for(int i=0; i<size; i++)
    hash_table[i].next = nullptr;

  return hash_table;
}

struct hash_node *
find_node(struct hash_node *hash_table, int size, int x)
{
  struct hash_node *cur = hash_table[x%size].next;

  while(cur!=nullptr) {
    if(cur->val==x) return cur;
    cur = cur->next;
  }

  return nullptr;
}

void
insert_node(struct hash_node *hash_table, int size, int x)
{
  struct hash_node *new_node = new hash_node(x);
  new_node->next = hash_table[x%size].next;
  hash_table[x%size].next = new_node;
}

void
delete_node(struct hash_node *hash_table, int size, int x)
{
  struct hash_node *cur = hash_table[x%size].next, *pre=&hash_table[x%size];

  while(cur!=nullptr) {
    if(cur->val==x) {
      pre->next = cur->next;
      delete cur;
      return;
    }
    pre = cur;
    cur = cur->next;
  }
}

static bool
cmp(pair<char, int> &l, pair<char, int> &s)
{
  return l.second>s.second;
}

void
print_order_chars(string s)
{
  unordered_map<char, int> m;
  unordered_map<char, int>::iterator iter;

  for(auto c : s)
    m[c] ++;

  vector<pair<char, int>> vec(m.begin(), m.end());
  sort(vec.begin(), vec.end(), cmp);
  for(int i=0; i<vec.size(); i++) {
    cout << vec[i].first << "->" << vec[i].second << endl;
  }
}
