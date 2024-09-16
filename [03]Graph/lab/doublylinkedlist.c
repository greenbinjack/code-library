// #author: greenbinjack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next, *prev;
} node;

node* list;

void init_list() {
    list = NULL;
}

void prepend(int element) {
    node* New = (node*) malloc(sizeof(node));
    New->value = element;
    New->next = NULL;
    New->prev = NULL;

    if(list == NULL) {
        list = New;
        return;
    }

    New->next = list;
    list->prev = New;
    list = New;
}

void append(int element) {
    node* New = (node*) malloc(sizeof(node));
    New->value = element;
    New->next = NULL;

    if(list == NULL) {
        list = New;
        return;
    }
    node* cur = list;
    while(cur->next != NULL) cur = cur->next;
    cur->next = New;
    New->prev = cur;
}

void insert_sorted(int element) {
    node* New = (node*) malloc(sizeof(node));
    New->value = element;
    New->next = NULL;
    New->prev = NULL;

    if(list == NULL) {
        list = New;
        return;
    }
    else if(element < list->value) {
        New->next = list;
        New->prev = NULL;
        list = New;
    }
    else {
        for(node* cur = list; cur != NULL; cur = cur->next) {
            if(cur->next == NULL) {
                cur->next = New;
                New->prev = cur;
            }
            else if(New->value < cur->next->value) {
                New->next = cur->next;
                New->prev = cur;
                cur->next = New;
                cur->next->prev = New;
                break;
            }
        }
    }
}

void insert_after(int element, int pred) {
    node* New = (node*) malloc(sizeof(node));
    New->value = element;
    New->next = NULL;
    New->prev = NULL;

    node* cur = list;
    while(cur->value != pred) cur = cur->next;

    if(cur->next != NULL) {
        New->next = cur->next;
        New->prev = cur;
        cur->next->prev = New;
        cur->next = New;
    }
    else {
        New->prev = cur;
        cur->next = New;
    }
}

void destroy(node* head) {
    if(head == NULL) {
        list = NULL;
        return;
    }
    destroy(head->next);
    free(head);
}

void delete_node(int element) {
    if(list == NULL) {
        printf("List is empty!\n");
        return;
    }
    node* cur = list;
    while(cur->value != element) cur = cur->next;
    if(cur->prev != NULL) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    free(cur);
}

void delete_front() {
    if(list == NULL) {
        printf("List is empty!\n");
        return;
    }
    node* head = list;
    list = list->next;
    list->prev = NULL;
    free(head);
}

void delete_back() {
    if(list == NULL) {
        printf("List is empty!\n");
        return;
    }
    node* cur = list;
    while(cur->next != NULL) cur = cur->next;
    if(cur->prev != NULL) cur->prev->next = NULL;
    else list = NULL;
    free(cur);
}

void print_list() {
    if(list == NULL) {
        printf("List is empty!\n");
        return;
    }
    for(node* head = list; head != NULL; head = head->next) {
        printf("%d ", head->value);
    }
    printf("\n");
}

bool find(int element) {
    for(node* trav = list; trav != NULL; trav = trav->next) {
        if(trav->value == element) return true;
    }
    return false;
}

int main() {
    init_list();

    // operations

    destroy(list);

    return 0;
}

