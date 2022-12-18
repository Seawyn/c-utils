#include <stdio.h>
#include "binary_tree.h"

int main(){
    Node* root = create_node(5);
    add_element(root, 7);
    add_element(root, 2);
    add_element(root, 1);
    add_element(root, 3);
    add_element(root, 8);
    add_element(root, 9);

    print_sorted(root);

    printf("Height of binary tree: %d\n", get_height(root));

    free_binary_tree(root);

    return 0;
}