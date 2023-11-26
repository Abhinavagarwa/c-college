#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary search tree node
struct Node {
    char type[20];
    char company[20];
    int year;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(char type[], char company[], int year) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->type, type);
    strcpy(node->company, company);
    node->year = year;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, char type[], char company[], int year) {
    if (root == NULL) {
        return newNode(type, company, year);
    }

    if (year < root->year) {
        root->left = insert(root->left, type, company, year);
    } else if (year > root->year) {
        root->right = insert(root->right, type, company, year);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int year) {
    if (root == NULL) {
        return root;
    }

    if (year < root->year) {
        root->left = deleteNode(root->left, year);
    } else if (year > root->year) {
        root->right = deleteNode(root->right, year);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        strcpy(root->type, temp->type);
        strcpy(root->company, temp->company);
        root->year = temp->year;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->year);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company, root->year);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company, root->year);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company, root->year);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insert(root, "Sedan", "Toyota", 2018);
    root = insert(root, "SUV", "Honda", 2020);
    root = insert(root, "Convertible", "BMW", 2019);
    root = insert(root, "Truck", "Ford", 2017);

    // Display the BST using inorder traversal
    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\n");

    // Display the BST using preorder traversal
    printf("Preorder Traversal:\n");
    preorderTraversal(root);
    printf("\n");

    // Display the BST using postorder traversal
    printf("Postorder Traversal:\n");
    postorderTraversal(root);
    printf("\n");

    // Delete a node
    int yearToDelete = 2019;
    root = deleteNode(root, yearToDelete);
    printf("Deleted node with year %d\n", yearToDelete);

    // Display the BST after deletion using inorder traversal
    printf("Inorder Traversal after deletion:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
