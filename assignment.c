#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *top = NULL; 

void push(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (top == NULL) {
        top = newNode;
    } else {
        struct node* temp = top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    int data;
    struct node* temp = top;

    if (top->next == NULL) {
        data = top->data;
        free(top);
        top = NULL;
        return data;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    struct node* lastNode = temp->next;
    data = lastNode->data;
    free(lastNode);
    temp->next = NULL;

    return data;
}

void display() {
    struct node* temp = top;
    printf("The stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty() {
    return top == NULL;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    struct node* temp = top;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    return temp->data;
}

int main() {
    push(1);
    push(2);
    push(3);
    display();

    push(4);
    display();

    printf("Top: %d\n", peek());
    pop();
    pop();
    display();

    pop();
    pop();
    display();

    return 0;
}
