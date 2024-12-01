#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    
    if (temp == NULL) {
        printf("Element %d not found\n", value);
        return;
    }
    
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Element %d deleted\n", value);
}

void search(int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", value);
}

void display() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    search(20);
    deleteNode(20);
    display();
    search(20);
    return 0;
}
