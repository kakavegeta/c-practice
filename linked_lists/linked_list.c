#include "linked_list.h"

void print(node *head) {
    node *cur = head;
    while (cur) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int size(node *head) {
    int count = 0;
    node *cur = head;
    while (cur) {
        cur = cur->next;
        count++;
    }
    return count;
}

bool is_empty(node *head) {
    return head==NULL; 
}

int value_at(node *head, int index) {
    node *cur = head;
    int i = 0;
    while (i<index && cur) {
        ++i;
        cur = cur->next;
    }
    if (!cur) {
        printf("The index exceeds limit");
        exit(EXIT_FAILURE);
    } else {
        return cur->val;
    }
}

void push_front(node **head, int val) {
    node *p = malloc(sizeof(node));
    p->val = val;
    p->next = *head;
    *head = p; } 
    
void push_back(node **head, int val) {
    node *p = malloc(sizeof(node));
    p->val = val;
    p->next = NULL;

    if (*head==NULL) {
        *head = p;
        return;
    }

    node *cur = *head;

    while (cur->next) {
        cur = cur->next;
    }

    cur->next = p;
}


int front(node *head) {
    if (head==NULL) {
        printf("the linked list is empty");
        exit(EXIT_FAILURE);
    }
    return head->val;
}

int end(node *head) {
    if (head==NULL) {
        printf("the linked list is empty");
        exit(EXIT_FAILURE);
    }
    node *cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    return cur->val;
}

void insert(node **head, int index, int val) {
    node **cur = head;
    int i;
    for (i=0; i<index && *cur; ++i) {
        cur = &(*cur)->next;
    }

    if (i != index){
        printf("index out of limit.");
        exit(EXIT_FAILURE);
    }

    node *new_node = malloc(sizeof(node));
    new_node->val = val;

    node *cur_node = *cur;
    new_node->next = cur_node;
    *cur = new_node;

} 
/* 
void remove(node **head, int index) {
    node **cur = head;
    int i;
    for (i=0; i<index&&*cur; ++i) {
        cur = &(*cur)->next;

    }
    if (i!=index) {
        printf("index out of limit");
        exit(EXIT_FAILURE);
    }

    *cur = (*cur)->next;
}
*/
int value_nth_from_end(node *head, int n) {
    if (n<1 || head==NULL) {
        printf("illegal linked list and index; n shoudld >=1.");
        exit(EXIT_FAILURE);
    }

    node *cur = head;
    node *match = head;
    int i;
    for (i=0; i<n && cur; ++i) {
        cur = cur->next;
    }

    if (i!=n) {
        printf("n is out of bound");
        exit(EXIT_FAILURE);
    }

    while (cur) {
        cur = cur->next;
        match = match->next;
    }

    return match->val;
}

void reverse(node **head) {
    node *cur = *head;
    node *prev = NULL, *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void reverse_recursive(node **head) {
    node *first, *rest;
    if (*head==NULL) {
        return;
    }

    first = *head;
    rest = first->next;

    if (rest==NULL) {
        return;
    }

    reverse_recursive(&rest);
    first->next->next = first;
    first->next;

    *head = rest;
}
