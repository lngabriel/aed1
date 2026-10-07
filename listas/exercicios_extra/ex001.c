#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    float value;
} Data;

typedef struct Node {
    Data data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Head;

Head *reset();
void append(Head *list, Data data);
void clear(Head *list);
void print(Head *list);

int main() {
    Head *list = reset();
    Data d1 = {"macbook", 599.00};
    Data d2 = {"iphone", 399.00};
    append(list, d1);
    append(list, d2);
    print(list);
    clear(list);
    print(list);
    free(list);
}

Head *reset() {
    Head *list = malloc(sizeof(Head));
    list->head = NULL;
    return list;
}

void append(Head *list, Data data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node *current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void clear(Head *list) {
    Node *current = list->head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}

void print(Head *list) {
    Node *current = list->head;

    printf("lista:\n");
    if (list->head == NULL) {
        printf("lista vazia\n");
        return;
    }

    while (current != NULL) {
        printf("nome: %s\npreco: %.2f\n\n", current->data.name, current->data.value);
        current = current->next;
    }
}