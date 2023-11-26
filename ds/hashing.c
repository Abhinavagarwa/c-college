#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for the linked list
typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

// Hash table structure
typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

// Hash function
int hash_function(char* key, int table_size) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31 + *key) % table_size;
        key++;
    }
    return hash;
}

// Create a new node
Node* create_node(char* key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Initialize a new hash table
HashTable* create_hash_table(int size) {
    HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
    hash_table->size = size;
    hash_table->table = (Node**)malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Insert a key-value pair into the hash table
void insert(HashTable* hash_table, char* key, int value) {
    int index = hash_function(key, hash_table->size);

    // Check if the index is empty (no collision)
    if (hash_table->table[index] == NULL) {
        hash_table->table[index] = create_node(key, value);
    } else {
        // Handle collision using chaining
        Node* current = hash_table->table[index];
        while (current->next != NULL && strcmp(current->key, key) != 0) {
            current = current->next;
        }

        // If the key already exists, update the value
        if (strcmp(current->key, key) == 0) {
            current->value = value;
        } else {
            // If the key doesn't exist in the chain, add a new node
            current->next = create_node(key, value);
        }
    }
}

// Search for a key in the hash table and return the corresponding value
int search(HashTable* hash_table, char* key) {
    int index = hash_function(key, hash_table->size);

    // Search through the chain for the key
    Node* current = hash_table->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return -1;
}

// Free the memory used by the hash table
void free_hash_table(HashTable* hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        Node* current = hash_table->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int main() {
    HashTable* hash_table = create_hash_table(TABLE_SIZE);

    // Insert key-value pairs
    printf("Enter key-value pairs (e.g., John 25):\n");
    char key[50];
    int value;

    while (1) {
        printf("Enter key and value (or type 'exit' to stop): ");
        scanf("%s", key);

        if (strcmp(key, "exit") == 0) {
            break;
        }

        scanf("%d", &value);

        insert(hash_table, key, value);
    }

    // Search for a key
    printf("Enter key to search: ");
    scanf("%s", key);

    int result = search(hash_table, key);
    if (result != -1) {
        printf("%s's value is: %d\n", key, result);
    } else {
        printf("Key not found\n");
    }

    // Free memory
    free_hash_table(hash_table);

    return 0;
}
