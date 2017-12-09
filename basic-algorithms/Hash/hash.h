/* hash table */

#ifndef __HASH_H
#define __HASH_H

#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct hash_node {
  int val;
  struct hash_node *next;
  hash_node(int x) { this->val=x; this->next=nullptr; }
};

struct hash_node *create_hash_table(int size);

struct hash_node *find_node(struct hash_node *hash_table, int size, int x);
void insert_node(struct hash_node *hash_table, int size, int x);
void delete_node(struct hash_node *hash_table, int size, int x);

void print_order_chars(string s);

#endif
