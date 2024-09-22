//STACK using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 5  // Maximum size of the stack

int stack[MAX];  // Stack array
int top = -1;    // Stack top pointer (initialized to -1, meaning stack is empty)

// Function to push an element onto the stack
void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if(top == -1) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from the stack\n", value);
    }
}

// Function to display the stack
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for(int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate stack operations
int main() {
    int choice, value;

    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
