/* main process */

#include "link_list.h"

#include <cstdio>

char list[] = {'K', 'o', 'b', 'e', ' ', 'a', 'n', 'd', ' ', 'L', 'o', 'n', 'z', 'o'};

int
main(int argc, char **argv)
{
  int L = sizeof(list) / sizeof(char);
  std::vector<char> v(&list[0], &list[L]);
  struct node *head = create_link_list(v, 0);
  traversal(head);

  struct node *new_head = reverse(head);
  printf("%d\n", length(new_head));
  traversal(new_head);

  return 0;
}
