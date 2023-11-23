#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct TwoStacks {
    int* array;
    int top1;
    int top2;
};

// Function to initialize the two stacks
struct TwoStacks* initializeTwoStacks() {
    struct TwoStacks* twoStacks = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
    if (!twoStacks) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    twoStacks->array = (int*)malloc(MAX_SIZE * sizeof(int));
    if (!twoStacks->array) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    twoStacks->top1 = -1;
    twoStacks->top2 = MAX_SIZE;

    return twoStacks;
}

// Function to push an element onto the first stack
void push1(struct TwoStacks* twoStacks, int data) {
    if (twoStacks->top1 < twoStacks->top2 - 1) {
        twoStacks->array[++twoStacks->top1] = data;
    } else {
        printf("Stack Overflow for Stack 1.\n");
    }
}

// Function to push an element onto the second stack
void push2(struct TwoStacks* twoStacks, int data) {
    if (twoStacks->top1 < twoStacks->top2 - 1) {
        twoStacks->array[--twoStacks->top2] = data;
    } else {
        printf("Stack Overflow for Stack 2.\n");
    }
}

// Function to pop an element from the first stack
int pop1(struct TwoStacks* twoStacks) {
    if (twoStacks->top1 >= 0) {
        return twoStacks->array[twoStacks->top1--];
    } else {
        printf("Stack 1 is empty.\n");
        return -1; // Stack underflow
    }
}

// Function to pop an element from the second stack
int pop2(struct TwoStacks* twoStacks) {
    if (twoStacks->top2 < MAX_SIZE) {
        return twoStacks->array[twoStacks->top2++];
    } else {
        printf("Stack 2 is empty.\n");
        return -1; // Stack underflow
    }
}

// Driver program to test the two stacks
int main() {
    struct TwoStacks* twoStacks = initializeTwoStacks();

    // Push elements onto the stacks
    push1(twoStacks, 1);
    push1(twoStacks, 2);
    push1(twoStacks, 3);

    push2(twoStacks, 4);
    push2(twoStacks, 5);
    push2(twoStacks, 6);

    // Pop elements from the stacks
    printf("Popped from stack 1: %d\n", pop1(twoStacks));
    printf("Popped from stack 2: %d\n", pop2(twoStacks));

    // Display the remaining elements in the array
    printf("Remaining elements in the array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", twoStacks->array[i]);
    }
    printf("\n");

    free(twoStacks->array);
    free(twoStacks);

    return 0;
}
