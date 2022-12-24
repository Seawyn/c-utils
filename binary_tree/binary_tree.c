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


Node* rotate_left(Node* cursor){
    Node *right = cursor->right;
    Node *subTree = right->left;

    cursor->right = subTree;
    right->left = cursor;

    return right;
}


Node* rotate_right(Node* cursor){
    Node *left = cursor->left;
    Node *subTree = left->right;

    cursor->left = subTree;
    left->right = cursor;

    return left;
}


Node* add_element(Node* cursor, float val){
    if (cursor == NULL) return create_node(val);
    else if (cursor->val > val) cursor->left = add_element(cursor->left, val);
    else if (cursor->val < val) cursor->right = add_element(cursor->right, val);

    int balance = get_height(cursor->left) - get_height(cursor->right);
    if (balance > 1){
        if (val > cursor->left->val) cursor->left = rotate_left(cursor->left);
        return rotate_right(cursor);
    }
    else if (balance < -1){
        if (val < cursor->right->val) cursor->right = rotate_right(cursor->right);
        return rotate_left(cursor);
    }

    return cursor;
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