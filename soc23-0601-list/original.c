#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    void* next;
} Node;

Node* NewNode(int value, Node* next) {
    Node* new = malloc(sizeof(Node));
    new->value = value;
    new->next = next;
    return new;
}


typedef struct {
    Node* head;
} List;

List NewList() {
    List lst = { .head = NULL };
    return lst;
}

void Erase(List* lst) {
    Node* current = lst->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    lst->head = NULL;
}

void PrintList(List* lst) {
    Node* temp = lst->head;

    printf("[ ");

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("]\n");

    free(temp);  // this works wtf?
}

void Push(List* lst, int val) {
    Node* new = NewNode(val, lst->head);
    lst->head = new;
}

void Pull(List* lst) {
    if (lst->head == NULL) {
        return;
    }
    Node* firstNode = lst->head;
    lst->head = lst->head->next;
    free(firstNode);
}


int GetAtIndex(List* lst, int index) {
    Node* temp = lst->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    int val = temp->value;

    return val;
}


int main() {
    List lst = NewList();

    Push(&lst, 6);
    Push(&lst, 7);
    Push(&lst, 8);
    Push(&lst, 9);
    PrintList(&lst);  // [ 9 8 7 6 ]

    PrintList(&lst);

    int index = 2;
    printf("lst[%d] = %d\n", index, GetAtIndex(&lst, index));

    PrintList(&lst);

    Erase(&lst);

    return 0;
}