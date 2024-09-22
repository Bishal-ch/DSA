#include<stdio.h>
#include<stdlib.h>
#define MAX 5  // Maximum size of the queue

int queue[MAX];  // Queue array
int front = -1;  // Front of the queue
int rear = -1;   // Rear of the queue

// Function to enqueue (add) an element to the queue
void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if(front == -1) front = 0; // Set front to 0 if it's the first element
        rear++;
        queue[rear] = value;
        printf("%d enqueued into the queue\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty\n");
    } else {
        printf("%d dequeued from the queue\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate queue operations
int main() {
    int choice, value;

    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
