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
void reverse(Head *list);
void index_to_remove(Head *list, int index);

int main() {
    Head *list = reset();
    Data d1 = {"macbook", 599.00};
    Data d2 = {"iphone", 399.00};
    append(list, d1);
    append(list, d2);
    print(list);
    index_to_remove(list, 2);
    print(list);
}

Head *reset() {
    Head *list = malloc(sizeof(Head));
    list->head = NULL;
    return list;
}

// inserindo no final da lista
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

// limpando a lista
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

void reverse(Head *list) {
    Node *current = list->head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    list->head = prev;
}

void index_to_remove(Head *list, int index) {
    Node *current = list->head;
    Node *prev = NULL;
    int i = 1;

    while (current != NULL) {
        if (index == i) {
            Node *remove = current;
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(remove);
        } else {
            prev = current;
            current = current->next;
        }
        i++;
    }
}