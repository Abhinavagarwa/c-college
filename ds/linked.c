#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    struct Student *next;
};

// Function to print the linked list
void displayList(struct Student *head) {
    struct Student *current = head;

    printf("Linked List:\n");

    while (current != NULL) {
        printf("Roll Number: %d, Name: %s\n", current->rollNumber, current->name);
        current = current->next;
    }

    printf("\n");
}

// Function to insert a new node at a specified position
void insertNode(struct Student **head, int position, int rollNumber, const char *name) {
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    newNode->rollNumber = rollNumber;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Student *current = *head;
    for (int i = 1; i < position - 1 && current != NULL; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position to insert.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node with a specified roll number
void deleteNode(struct Student **head, int rollNumberToDelete) {
    struct Student *temp = *head;
    struct Student *prev = NULL;

    if (temp != NULL && temp->rollNumber == rollNumberToDelete) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->rollNumber != rollNumberToDelete) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to reverse the linked list
void reverseList(struct Student **head) {
    struct Student *prev = NULL;
    struct Student *current = *head;
    struct Student *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to free memory allocated for the linked list
void freeList(struct Student **head) {
    struct Student *current = *head;
    struct Student *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Student *head = NULL;

    // Insert nodes
    insertNode(&head, 1, 101, "Alice");
    insertNode(&head, 2, 102, "Bob");
    insertNode(&head, 3, 103, "Charlie");

    // Display the original linked list
    displayList(head);

    // Insert a new node at a specified position
    insertNode(&head, 2, 104, "David");
    printf("Linked List after insertion:\n");
    displayList(head);

    // Delete a node with a specified roll number
    deleteNode(&head, 102);
    printf("Linked List after deletion:\n");
    displayList(head);

    // Reverse the linked list
    reverseList(&head);
    printf("Linked List after reversal:\n");
    displayList(head);

    // Free memory allocated for the linked list
    freeList(&head);

    return 0;
}
