#include "bst.h"
t_btree* bstree_create_node(int item) {
    t_btree* root;
    root = malloc(sizeof(t_btree));
    root -> key = item;
    root -> parent = NULL;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}
int compare(int curr, int next) {
    int res = 0;
    if (curr >= next) res = 1;
    return res;
}
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree* root2 = root, *root3 = NULL;
    t_btree *tmp = malloc(sizeof(t_btree));
    tmp->key = item;
    while (root2 != NULL) {
        root3 = root2;
        if (cmpf(root2->key, item)) {
            root2 = root2->left;
        } else {
            root2 = root2->right;
        }
    }
    tmp -> parent = root3;
    tmp -> left = NULL;
    tmp -> right = NULL;
    if (item <= root3 -> key) {
        root3 -> left = tmp;
    } else {
        root3 -> right = tmp;
    }
}
