/* binary tree algorithms */

#include "bin_tree.h"

#include <cstdio>

struct node *
create_bin_tree(std::vector<char> v, int start)
{
  if(v.size()==0) return nullptr;

  if(v[start]=='#') return nullptr;
  struct node *root = new node(v[start]);

  int l_index = 2 * start + 1;
  int r_index = 2 * start + 2;
  if(l_index>v.size()-1)  root->left = nullptr;
  else  root->left = create_bin_tree(v, l_index);
  if(r_index>v.size()-1)  root->right = nullptr;
  else  root->right = create_bin_tree(v, r_index);

  return root;
}

void
pre_order_traversal(struct node *root)
{
  std::stack<struct node *> s;
  struct node *p = root;

  while(!s.empty() || p!=nullptr) {
    if(p!=nullptr) {
      printf("%c", p->ch);
      s.push(p);
      p = p->left;
    }
    else {
      p = s.top();
      s.pop();
      p = p->right;
    }
  }
}

void
pre_order_traversal_recur(struct node *root)
{
  if(root==nullptr) return;
  printf("%c", root->ch);
  pre_order_traversal_recur(root->left);
  pre_order_traversal_recur(root->right);
}

void
in_order_traversal(struct node *root)
{
  std::stack<struct node *> s;
  struct node *p = root;

  while(!s.empty() || p!=nullptr) {
    if(p!=nullptr) {
      s.push(p);
      p = p->left;
    }
    else {
      p = s.top();
      printf("%c", p->ch);
      s.pop();
      p = p->right;
    }
  }
}

void
in_order_traversal_recur(struct node *root)
{
  if(root==nullptr) return;
  in_order_traversal_recur(root->left);
  printf("%c", root->ch);
  in_order_traversal_recur(root->right);
}

void
post_order_traversal(struct node *root)
{
  std::stack<struct node *> s;
  struct node *p = root, *last = nullptr;

  while(p!=nullptr) {
    s.push(p);
    p = p->left;
  }
  while(!s.empty()) {
    p = s.top();
    s.pop();
    if(p->right==nullptr || p->right==last) {
      printf("%c", p->ch);
      last = p;
    }
    else {
      s.push(p);
      p = p->right;
      while(p!=nullptr) {
        s.push(p);
        p = p->left;
      }
    }
  }
}

void
post_order_traversal_recur(struct node *root)
{
  if(root==nullptr) return;
  post_order_traversal_recur(root->left);
  post_order_traversal_recur(root->right);
  printf("%c", root->ch);
}

void
level_traversal(struct node *root)
{
  std::queue<struct node *> q;

  if(root==nullptr) return;
  q.push(root);
  while(q.size()!=0) {
    struct node *t = q.front();
    printf("%c", t->ch);
    q.pop();
    if(t->left!=nullptr)  q.push(t->left);
    if(t->right!=nullptr) q.push(t->right);
  }
}

void
reverse(struct node *root)
{
  if(root==nullptr) return;
  std::stack<struct node *> s;

  s.push(root);
  while(!s.empty()) {
    struct node *p = s.top();
    s.pop();
    struct node *t = p->left;
    p->left = p->right;
    p->right = t;
    if(p->left) s.push(p->left);
    if(p->right)  s.push(p->right);
  }
}

void
reverse_recur(struct node *root)
{
  if(root==nullptr) return;
  struct node *l = root->left;
  struct node *r = root->right;
  root->left = r;
  root->right = l;
  reverse_recur(root->left);
  reverse_recur(root->right);
}

int
depth(struct node *root)
{
  if(root==nullptr) return 0;
  int l_h = depth(root->left);
  int r_h = depth(root->right);
  return (l_h>r_h) ? (l_h+1) : (r_h+1);
}

int
depth_1(struct node *root)
{
  if(root==nullptr)
    return 0;
  std::queue<struct node *> q;
  int height = 0;

  q.push(root);
  while(!q.empty()) {
    height ++;
    for(int i=0; i<q.size(); i++) {
      struct node *t = q.front();
      q.pop();
      if(t->left!=nullptr)
        q.push(t->left);
      if(t->right!=nullptr)
        q.push(t->right);
    }
  }

  return height;
}
