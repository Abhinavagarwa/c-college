#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Employee structure
struct Employee {
    int emp_id;
    char emp_name[50];
    char emp_position[50];
    struct Employee* next;
    struct Employee* prev;
};

// Doubly Linked List structure
struct DoublyLinkedList {
    struct Employee* head;
    struct Employee* tail;
};

// Function to insert at the front of the doubly linked list
void insert_at_front(struct DoublyLinkedList* list, int emp_id, const char* emp_name, const char* emp_position) {
    struct Employee* new_employee = (struct Employee*)malloc(sizeof(struct Employee));
    new_employee->emp_id = emp_id;
    strcpy(new_employee->emp_name, emp_name);
    strcpy(new_employee->emp_position, emp_position);
    new_employee->next = NULL;
    new_employee->prev = NULL;

    if (list->head == NULL) {
        // If the list is empty, set both head and tail to the new node
        list->head = new_employee;
        list->tail = new_employee;
    } else {
        // Update links to insert at the front
        new_employee->next = list->head;
        list->head->prev = new_employee;
        list->head = new_employee;
    }
}

// Function to delete at the end of the doubly linked list
void delete_at_end(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    struct Employee* deleted_employee;

    if (list->head->next == NULL) {
        // If there is only one node in the list
        deleted_employee = list->head;
        list->head = NULL;
        list->tail = NULL;
    } else {
        // Traverse to the end of the list
        struct Employee* current = list->head;
        while (current->next) {
            current = current->next;
        }

        // Delete the last node
        deleted_employee = current;
        current->prev->next = NULL;
        list->tail = current->prev;
    }

    printf("Deleted Employee: %s\n", deleted_employee->emp_name);
    free(deleted_employee);
}

// Function to display the doubly linked list
void display_list(struct DoublyLinkedList* list) {
    struct Employee* current = list->head;
    while (current) {
        printf("Employee ID: %d, Name: %s, Position: %s\n", current->emp_id, current->emp_name, current->emp_position);
        current = current->next;
    }
}

// Main function for example usage
int main() {
    // Creating a doubly linked list
    struct DoublyLinkedList doubly_linked_list;
    doubly_linked_list.head = NULL;
    doubly_linked_list.tail = NULL;

    // Inserting at the front
    insert_at_front(&doubly_linked_list, 1, "John Doe", "Manager");
    insert_at_front(&doubly_linked_list, 2, "Jane Doe", "Developer");
    insert_at_front(&doubly_linked_list, 3, "Bob Smith", "Designer");

    // Displaying the list
    printf("Doubly Linked List:\n");
    display_list(&doubly_linked_list);

    // Deleting at the end
    delete_at_end(&doubly_linked_list);

    // Displaying the updated list
    printf("\nDoubly Linked List after deletion:\n");
    display_list(&doubly_linked_list);

    return 0;
}
