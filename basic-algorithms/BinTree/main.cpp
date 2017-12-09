/* main process */

#include "bin_tree.h"

#include <cstdio>

char tree[] = {'K', 'o', 'b', 'e', '#', '#', '!'};

int
main(int argc, char **argv)
{
  int L = sizeof(tree)/sizeof(char);
  std::vector<char> v(&tree[0], &tree[L]);
  struct node *root = create_bin_tree(v, 0);

  printf("%d, %d\n", depth(root), depth_1(root));

  // pre_order_traversal(root);

  // reverse(root);
  // pre_order_traversal(root);

  return 0;
}
