#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
int is_list_empty(struct Node** head);
int list_length(struct Node** head);
int search(struct Node* head, int data);
void print_nodes(struct Node* head);
void insert(struct Node** head, int data);
void remove_first(struct Node** head);
void insert_at(struct Node** head, int data, int pos);
void insert_last(struct Node** head, int data);
void remove_nth(struct Node** head, int nth);
void find(struct Node* head, int data);
void remove_data(struct Node** head, int data);

#endif // LINKEDLIST_H

