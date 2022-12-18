#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct Node Node;

struct Node{
    float val;
    Node *left, *right;
};

int max(int a, int b);
Node* create_node(float val);
Node* find_place(Node* cursor, float val);
void add_element(Node* root, float val);
int get_height(Node* cursor);
void print_sorted(Node* cursor);
void free_binary_tree(Node* cursor);


#endif