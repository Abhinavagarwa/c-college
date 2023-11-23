#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int rollNumber;
    char name[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int rollNumber, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->rollNumber = rollNumber;
    snprintf(newNode->name, sizeof(newNode->name), "%s", name);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at a specified position
void insertNodeAtPosition(struct Node** head, int position, int rollNumber, const char* name) {
    struct Node* newNode = createNode(rollNumber, name);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at the beginning.\n");
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Node not inserted.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

// Function to delete a node with the specified roll number
void deleteNodeByRollNumber(struct Node** head, int rollNumber) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Check if the node to be deleted is the head
    if (temp != NULL && temp->rollNumber == rollNumber) {
        *head = temp->next;
        free(temp);
        printf("Node with roll number %d deleted.\n", rollNumber);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->rollNumber != rollNumber) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with roll number %d not found. Deletion failed.\n", rollNumber);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with roll number %d deleted.\n", rollNumber);
}

// Function to reverse the linked list
void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("Linked list reversed.\n");
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list elements:\n");
    while (temp != NULL) {
        printf("Roll Number: %d, Name: %s\n", temp->rollNumber, temp->name);
        temp = temp->next;
    }
    printf("\n");
}

// Function to deallocate memory used by the linked list
void destroyLinkedList(struct Node** head) {
    while (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Driver program to test the linked list operations
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertNodeAtPosition(&head, 1, 101, "Alice");
    insertNodeAtPosition(&head, 2, 102, "Bob");
    insertNodeAtPosition(&head, 3, 103, "Charlie");

    // Display original linked list
    displayLinkedList(head);

    // Delete a node
    deleteNodeByRollNumber(&head, 102);
    displayLinkedList(head);

    // Reverse the linked list
    reverseLinkedList(&head);
    displayLinkedList(head);

    // Deallocate memory
    destroyLinkedList(&head);

    return 0;
}
