#ifndef SRC_BST_H_
#define SRC_BST_H_
#include <stdlib.h>
typedef struct t_btree {
    int key;
    struct t_btree* right;
    struct t_btree* left;
    struct t_btree* parent;
} t_btree;
t_btree* bstree_create_node(int item);
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
int compare(int curr, int next);
#endif  //  SRC_BST_H_
