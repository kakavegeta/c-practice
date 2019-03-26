#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

typedef struct Node {
    int val;
    struct Node *next;
} node;

void print(node *head);
int size(node *head);
bool is_empty(node *head);
int value_at(node *head, int index);
void push_front(node **head, int val);
void push_back(node **head, int val);
int pop_front(node **head);
int pop_back(node **head);
int front(node *head);
int end(node *head);
void insert(node **head, int index, int val);
void remove(node **head, int index);
int value_nth_from_end(node *head, int n);
void reverse(node **head);
void reverse_recursive(node **head);
void remove_value(node **head, int val);

void check_address(node *addr);
void destory(node *head);


#endif