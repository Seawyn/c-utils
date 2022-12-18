#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


int max(int a, int b){
    return a > b ? a : b;
}


Node* create_node(float val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* find_place(Node* cursor, float val){
    if (cursor->val == val){
        return NULL;
    } else if (cursor->val < val) {
        if (cursor->right == NULL) return cursor;
        else{
            return find_place(cursor->right, val);
        }
    } else{
        if (cursor->left == NULL) return cursor;
        else{
            return find_place(cursor->left, val);
        }
    }
}


void add_element(Node* root, float val){
    Node* final = find_place(root, val);

    if (final == NULL){
        printf("Found duplicate element: %f\n", val);
        return;
    }

    Node* new = create_node(val);
    
    if (final->val > val) final->left = new;
    else final->right = new;
}

int get_height(Node* cursor){
    if (cursor == NULL) return 0;
    else return 1 + max(get_height(cursor->left), get_height(cursor->right));
}


void print_sorted(Node* cursor){
    if (cursor->left != NULL) print_sorted(cursor->left);
    printf("%f\n", cursor->val);
    if (cursor->right != NULL) print_sorted(cursor->right);
}

void free_binary_tree(Node* cursor){
    if (cursor->left != NULL) free_binary_tree(cursor->left);
    if (cursor->right != NULL) free_binary_tree(cursor->right);
    free(cursor);
}