#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    char collegeInfo[100];  // Information about the college
    struct Node* next;      // Pointer to the next node
};

// Function to insert a new node at the front of the circular linked list
struct Node* insert_at_front(struct Node* head, char info[]) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return head;
    }

    // Copy college information to the new node
    snprintf(new_node->collegeInfo, sizeof(new_node->collegeInfo), "%s", info);

    if (!head) {
        // If the list is empty, make the new node the head and point to itself
        head = new_node;
        new_node->next = head;
    } else {
        // If the list is not empty, insert at the front
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    return head;
}

// Function to delete the last node from the circular linked list
struct Node* delete_at_end(struct Node* head) {
    if (!head) {
        printf("List is empty. Deletion not possible.\n");
        return NULL;
    }

    if (head->next == head) {
        // If there's only one node in the list, delete it
        free(head);
        return NULL;
    }

    // Traverse the list to find the second-to-last node
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    // Delete the last node
    free(temp->next);
    temp->next = head;

    return head;
}

// Function to print the circular linked list
void print_list(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%s -> ", temp->collegeInfo);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    // Insertion at the front
    head = insert_at_front(head, "College A");
    head = insert_at_front(head, "College B");
    head = insert_at_front(head, "College C");

    // Display the list after insertion
    printf("List after insertion:\n");
    print_list(head);

    // Deletion at the end
    head = delete_at_end(head);

    // Display the list after deletion
    printf("List after deletion:\n");
    print_list(head);

    return 0;
}
