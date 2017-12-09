/* binary tree algorithms */

#ifndef __BIN_TREE_H
#define __BIN_TREE_H

#include <vector>
#include <queue>
#include <stack>

struct node {
  char ch;
  struct node *left, *right;
  node(char ch) { this->ch = ch; this->left = this->right = nullptr; }
};

struct node *create_bin_tree(std::vector<char> v, int start);

void pre_order_traversal(struct node *root);
void pre_order_traversal_recur(struct node *root);
void in_order_traversal(struct node *root);
void in_order_traversal_recur(struct node *root);
void post_order_traversal(struct node *root);
void post_order_traversal_recur(struct node *root);
void level_traversal(struct node *root);

void reverse(struct node *root);
void reverse_recur(struct node *root);

int depth(struct node *root);
int depth_1(struct node *root);

#endif
