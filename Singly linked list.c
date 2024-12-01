#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
}

void deleteNode(int value) {
    struct Node* temp = head, *prev = NULL;
    
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Element %d deleted\n", value);
        return;
    }
    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %d not found\n", value);
        return;
    }
    
    prev->next = temp->next;
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
    printf("Singly Linked List: ");
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
