// #author: greenbinjack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node* list;

void init_list() {
    list = NULL;
}

void prepend(int element) {
    node* New = (node*)malloc(sizeof(node));
    New->value = element;
    New->next = NULL;

    if (list == NULL) New->next = New;
    else {
        node* last = list;
        while (last->next != list) last = last->next;
        last->next = New;
        New->next = list;
    }
    list = New;
}

void append(int element) {
    node* New = (node*)malloc(sizeof(node));
    New->value = element;
    New->next = NULL;

    if (list == NULL) {
        list = New;
        New->next = New;
        list = New;
    } else {
        node* last = list;
        while (last->next != list) {
            last = last->next;
        }
        last->next = New;
        New->next = list;
    }
}

void insert_sorted(int element) {
    node* New = (node*)malloc(sizeof(node));
    New->value = element;
    New->next = NULL;
    if (list== NULL || element < list->value) {
        New->next = list;
        if (list != NULL) {
            node* last = list;
            while (last->next != list) last = last->next;
            last->next = New;
        } else New->next = New;
        list = New;
        return;
    }
    node* cur = list;
    while (cur->next != list && cur->next->value < element) cur = cur->next;
    New->next = cur->next;
    cur->next = New;
}

void insert_after(int pred_val, int element) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    node* pred = list;
    while (pred->value != pred_val) pred = pred->next;
    node* New = (node*)malloc(sizeof(node));
    New->value = element;
    New->next = pred->next;
    pred->next = New;
    if (pred->next == list) list = New;
}

void delete_front() {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->next == list) {
        free(list);
        list = NULL;
        return;
    }
    node* last = list;
    while (last->next != list) last = last->next;
    node* second = list->next;
    last->next = second;
    free(list);
    list = second;
}

void delete_back() {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->next == list) {
        free(list);
        list = NULL;
        return;
    }
    node* second_last = list;
    while (second_last->next->next != list) second_last = second_last->next;
    node* last = second_last->next;
    second_last->next = list;
    free(last);
}

void delete_node(int element) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->value == element) {
        node* last = list;
        while (last->next != list) last = last->next;
        if (list->next == list) {
            free(list);
            list = NULL;
        } else {
            node* temp = list;
            list = list->next;
            last->next = list;
            free(temp);
        }
        return;
    }
    node* pred = list;
    while (pred->next != list && pred->next->value != element) pred = pred->next;
    node* del_node = pred->next;
    pred->next = del_node->next;
    free(del_node);
}


void destroy() {
    if (list == NULL) return;
    node* cur = list;
    node* temp;
    do {
        temp = cur;
        cur = cur->next;
        free(temp);
    } while (cur != list);
    list = NULL;
}

void print_list() {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    node* cur = list;
    do {
        printf("%d ", cur->value);
        cur = cur->next;
    } while (cur != list);
    printf("\n");
}

bool find(int element) {
    if (list == NULL) return false;
    node* cur = list;
    do {
        if (cur->value == element) return true;
        cur = cur->next;
    } while (cur != list);
    return false;
}

int main() {
    init_list();

    // operations

    destroy(list);

    return 0;
}

