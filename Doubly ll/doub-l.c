#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

// Insert a node at the end of the doubly linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

// Insert a node at a specific position in the doubly linked list
Node* insertAtPosition(Node* head, int position, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        if (position == 1) {
            return newNode;
        } else {
            printf("Position out of range\n");
            return head;
        }
    }

    Node* temp = head;
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    } else {
        for (int i = 0; i < position - 2 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            return head;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

// Delete a node with a specific value from the doubly linked list
Node* deleteNode(Node* head, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    Node* temp = head;

    // Deleting head node
    if (head->data == value) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    // Searching for the node to be deleted
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) {
        printf("Node with value %d not found\n", value);
        return head;
    }

    // Node found, delete it
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);

    return head;
}

// Search for a node in the doubly linked list
void search(Node* head, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Node with value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Node with value %d not found\n", value);
}

// Display the doubly linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, i, v, choice, pos, iv;

    // Creating doubly linked list
    printf("Enter Doubly Linked List size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter node value: ");
        scanf("%d", &v);
        head = insertEnd(head, v);
    }

    printf("\n1) Display\n2) Insert\n3) Delete\n4) Search\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        display(head);
        break;

    case 2:
        printf("Enter position and value to insert: ");
        scanf("%d %d", &pos, &iv);
        head = insertAtPosition(head, pos, iv);
        display(head);
        break;

    case 3:
        printf("Enter value to delete: ");
        scanf("%d", &iv);
        head = deleteNode(head, iv);
        display(head);
        break;

    case 4:
        printf("Enter value to search: ");
        scanf("%d", &iv);
        search(head, iv);
        break;

    default:
        printf("Invalid option\n");
        break;
    }

    return 0;
}
