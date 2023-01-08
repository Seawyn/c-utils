#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkEl* init_list(void* data){
    LinkEl* head = (LinkEl*)malloc(sizeof(LinkEl));
    head->id = 0;
    head->data = data;

    return head;
}

int add_link(LinkEl* head, void *data){
    LinkEl* cursor = head;

    while(cursor->next != NULL){
        cursor = cursor->next;
    }

    LinkEl* new = (LinkEl*)malloc(sizeof(LinkEl));
    new->id = cursor->id + 1;
    new->data = data;
    new->prev = cursor;
    cursor->next = new;
    return cursor->next->id;
}


int search_list(LinkEl* head, void *data){
    LinkEl* cursor = head;

    while(cursor != NULL){
        if (cursor->data == data) return cursor->id;
        cursor = cursor->next;
    }

    return -1;
}


int list_size(LinkEl* head){
    int size = 0;
    LinkEl* cursor = head;

    while (cursor != NULL){
        size++;
        cursor = cursor->next;
    }

    return size;
}


int delete_link(LinkEl* head, int id){
    LinkEl* cursor = head;
    while (cursor->id < id && cursor->next != NULL) cursor = cursor->next;
    if (cursor->id == id){
        LinkEl *prev = cursor->prev;
        LinkEl *next = cursor->next;

        cursor->prev = NULL;
        cursor->next = NULL;

        // replace pointers to selected element

        prev->next = next;
        next->prev = prev;

        free(cursor->data);
        free(cursor);

        // Update ids
        while (next != NULL){
            next->id = next->prev->id + 1;
            next = next->next;
        }

        return id;
    }

    else return -1;
}

void free_list(LinkEl* head){
    LinkEl* cursor = head;
    
    while (cursor->next != NULL){
        cursor = cursor->next;
        free(cursor->data);
        free(cursor->prev);
    }

    //free(cursor->data);
    //free(cursor);
}