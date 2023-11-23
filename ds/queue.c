#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to insert an element into the queue (enqueue)
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued %d into the queue.\n", data);
}

// Function to delete an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        return -1; // Return an arbitrary value to indicate underflow
    }
    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;

    if (queue->front == queue->rear) {
        // If there's only one element in the queue
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = temp->next;
    }

    free(temp);
    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the elements of the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to deallocate memory used by the queue
void destroyQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Driver program to test the queue operations
int main() {
    struct Queue* queue = initializeQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);

    displayQueue(queue);

    enqueue(queue, 40);
    enqueue(queue, 50);

    displayQueue(queue);

    destroyQueue(queue);

    return 0;
}
