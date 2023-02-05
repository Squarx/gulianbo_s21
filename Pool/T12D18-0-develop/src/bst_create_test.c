#include "bst.h"
#include <stdio.h>
t_btree* test_root(int first, int second);
int main() {
test_root(5, 3);
return 0;
}
t_btree* test_root(int first, int second) {
t_btree* root = bstree_create_node(first);
printf("Parent: %p, Right_elem = %p, Left_elem = %p, Root Key = %d", root->parent,
 root->left, root->right, root->key);
t_btree* root1 = bstree_create_node(second);
printf("\nParent: %p, Right_elem = %p, Left_elem = %p, Root1 Key = %d\n",
root->parent, root1->left, root1->right, root1->key);
free(root);
free(root1);
return root;
}
