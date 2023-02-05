#include "bst.h"
#include <stdio.h>
t_btree* test_root(int first);
void test_add(t_btree* root);
int main() {
t_btree* root = test_root(5);
test_add(root);
free(root->left->left);
free(root->left->right);
free(root->left);
free(root->right);
free(root);
return 0;
}

void test_add(t_btree* root) {
bstree_insert(root, 8, compare);
bstree_insert(root, 2, compare);
printf("\nRight Key = %d, Parent key = %d", root->right->key, root->right->parent->key);
printf("\nLeft Key = %d, Parent key = %d", root->left->key, root->left->parent->key);
bstree_insert(root, 4, compare);
bstree_insert(root, 2, compare);
printf("\nRight Key = %d, Parent key = %d", root->left->right->key, root->left->right->parent->key);
printf("\nLeft Key = %d, Parent key = %d", root->left->left->key, root->left->left->parent->key);
}
t_btree* test_root(int first) {
t_btree* root = bstree_create_node(first);
printf("Parent: %p, Right_elem = %p, Left_elem = %p, Root Key = %d", root->parent,
 root->left, root->right, root->key);
return root;
}
