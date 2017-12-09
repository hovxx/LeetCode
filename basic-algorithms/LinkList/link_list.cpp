/* link list algorithms */

#include "link_list.h"

#include <cstdio>


struct node *
create_link_list(std::vector<char> &v, int start)
{
  if(v.size()==0) return nullptr;
  if(start>v.size()-1)  return nullptr;
  struct node *head = new node(v[start]);
  head->next = create_link_list(v, start+1);
  return head;
}

int
length(struct node *head)
{
  struct node *p = head;
  int num = 0;

  while(p!=nullptr) {
    num ++;
    p = p->next;
  }

  return num;
}

void
traversal(struct node *head)
{
  struct node *p = head;

  while(p!=nullptr) {
    printf("%c", p->ch);
    p = p->next;
  }
}

struct node *
reverse(struct node *head)
{
  if(head==nullptr) return nullptr;
  struct node *pre=nullptr, *cur=head, *next;

  while(cur!=nullptr) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}
