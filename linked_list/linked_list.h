#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct LinkEl LinkEl;

struct LinkEl{
    int id;
    void *data;
    LinkEl *prev, *next;
};

LinkEl* init_list(void* data);
int add_link(LinkEl* head, void *data);
int search_list(LinkEl* head, void *data);
int list_size(LinkEl* head);
int delete_link(LinkEl* head, int id);
void free_list(LinkEl* head);

#endif