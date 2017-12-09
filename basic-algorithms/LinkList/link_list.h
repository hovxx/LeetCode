/* Link list algorithms */

#ifndef __LINK_LIST_H
#define __LINK_LIST_H

#include <vector>

struct node {
  char ch;
  struct node *next;
  node(char ch) { this->ch = ch; this->next = nullptr; }
};


struct node *create_link_list(std::vector<char> &v, int start);

int length(struct node *head);
void traversal(struct node *head);

struct node *reverse(struct node *head);

#endif
