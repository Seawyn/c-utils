#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct TestObj TestObj;
struct TestObj{
    int n;
};

void print_list(LinkEl* head){
    LinkEl* cursor = head;

    while(cursor != NULL){
        TestObj* tmp = (TestObj*) cursor->data;
        printf("%d - %d\n", cursor->id, tmp->n);
        cursor = cursor->next;
    }
}

int main(void){
    int elements[10] = {0, 15, 24, 45, 32, 13, 53, 64, 231, 1833};

    TestObj* tmp = (TestObj*)malloc(sizeof(TestObj));
    tmp->n = elements[0];
    LinkEl* head = init_list(tmp);

    for (int i = 1; i < 10; i++){
        TestObj* tmp = (TestObj*)malloc(sizeof(TestObj));
        tmp->n = elements[i];
        add_link(head, tmp);
    }

    printf("List size: %d\n", list_size(head));
    print_list(head);

    printf("\nDeleting 5th element...\n");
    delete_link(head, 5);
    printf("List size: %d\n", list_size(head));
    print_list(head);

    free_list(head);

    return 0;
}