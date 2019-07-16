#include "linked_list.h"
#include "linked_list.c"
#include "assert.h"
#include "stdlib.h"


void test_size(){
    node *head = NULL;
    assert(size(head)==0);
    node *first = malloc(sizeof(node));
    //check_address(first);
    first->val = 1;
    first->next = NULL;
    head = first;
    print(head);
    assert(size(head)==1);

}

void test_push_front(){
    node *head = NULL;
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    print(head);
}

void test_push_back(){
    node *head = NULL;
    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    print(head);
}



void main(){
    test_size();
    test_push_front();
    test_push_back();
    system("pause");
    //return EXIT_SUCCESS;

}