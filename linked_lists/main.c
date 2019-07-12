#include "linked_list.h"
#include "linked_list.c"


void test_size(){
    node *head = NULL;
    assert(size(head)==0);
    node *first = malloc(sizeof(node));
    check_address(first);
    first->val = 1;
    first->next = NULL;
    head = first;
    assert(size(head)==1);

}

void main(){
    test_size();
    return EXIT_SUCCESS;

}