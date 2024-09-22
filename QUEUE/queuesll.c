// QUEUE USING SLL      -Bishal 

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

Node *enqueue(Node *rear, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (front == NULL) { // Queue is empty
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode; // Update the rear to the new node
    }
    return rear; // Return the updated rear
}

Node *dequeue(Node *front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return NULL;
    }
    Node *temp = front;
    printf("%d dequeued from the queue\n", front->data);
    front = front->next; // Move front to the next node
    free(temp); // Free the dequeued node
    return front;
}

void display(Node *front) {
    Node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(Node *front) {
    Node *temp = front;
    int flag = 0, v;
    printf("\nEnter value to search: ");
    scanf("%d", &v);
    
    while (temp != NULL) {
        if (temp->data == v) {
            printf("\nFound %d\n", temp->data);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (!flag) {
        printf("Not found\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1 Enqueue\n2 Dequeue\n3 Display\n4 Search\n5 Exit:");
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                rear = enqueue(rear, value); // Enqueue a new element
                display(front); // Display the queue
                break;
            case 2:
                front = dequeue(front); // Dequeue an element
                display(front); // Display the queue
                break;
            case 3:
                display(front); // Display the queue
                break;
            case 4:
                search(front); // Search for a value in the queue
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid option!\n");
        }
    }

    return 0;
}
