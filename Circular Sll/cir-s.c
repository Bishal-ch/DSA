#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;  // For circular linked list, point to itself
    return newNode;
}

// Insert at the end of the circular linked list
Node *insertEnd(Node *last, int data) {
    Node *newNode = create(data);
    if (last == NULL) {
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

// Display the circular linked list
void display(Node *last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = last->next;
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("NULL\n");
}

// Insert a node at a specific position in the circular linked list
Node *insertAtPosition(Node *last, int position, int value) {
    display(last);
    Node *newNode = create(value);
        if (last == NULL) {
        return newNode;
    }
    Node *temp = last->next;
    if (position == 1) {
        newNode->next = last->next;
        last->next = newNode;
        return last;
    } else {
        for (int i = 0; i < position - 2 && temp->next != last->next; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == last) {
            last = newNode;
        }
    }
    return last;
}

// Delete a node with a specific value from the circular linked list
Node *deleteNode(Node *last, int value) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    Node *temp = last->next, *prev = last;
    if (last->next == last && last->data == value) {
        free(last);
        return NULL;
    }
    do {
        if (temp->data == value) {
            prev->next = temp->next;
            if (temp == last) {
                last = prev;
            }
            free(temp);
            return last;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
    printf("Node with value %d not found\n", value);
    return last;
}

// Search for a node in the circular linked list
void search(Node *last, int value) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = last->next;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Node with value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    printf("Node with value %d not found\n", value);
}

int main() {
    Node *last = NULL;
    int n, i, v, choice, pos, iv;

    // Creating circular linked list
    printf("Enter Circular Linked List size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter node value: ");
        scanf("%d", &v);
        last = insertEnd(last, v);
    }

    printf("\n1) Display\n2) Insert\n3) Delete\n4) Search\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        display(last);
        break;

    case 2:
        printf("Enter position and value to insert: ");
        scanf("%d %d", &pos, &iv);
        last = insertAtPosition(last, pos, iv);
        display(last);
        break;

    case 3:
        printf("Enter value to delete: ");
        scanf("%d", &iv);
        last = deleteNode(last, iv);
        display(last);
        break;

    case 4:
        printf("Enter value to search: ");
        scanf("%d", &iv);
        search(last, iv);
        break;

    default:
        printf("Invalid option\n");
        break;
    }

    return 0;
}
