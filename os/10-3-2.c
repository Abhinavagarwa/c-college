#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Structure for the index table
struct IndexTable {
    int id;
    int position;
};

// Structure to represent a record in the file
struct Record {
    int id;
    char name[20];
};

struct IndexTable indexTable[MAX];
int indexCount = 0;

// Function to create an indexed file
void createIndexedFile() {
    FILE *file = fopen("indexed.dat", "wb");
    int n, i;
    struct Record rec;
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter number of records: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter ID and Name: ");
        scanf("%d %s", &rec.id, rec.name);
        fwrite(&rec, sizeof(rec), 1, file);
        
        indexTable[indexCount].id = rec.id;
        indexTable[indexCount].position = i;
        indexCount++;
    }
    
    fclose(file);
    printf("Indexed file created successfully!\n");
}

// Function to search a record using index
void searchIndexedFile() {
    int searchId, found = 0;
    FILE *file = fopen("indexed.dat", "rb");
    struct Record rec;
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == searchId) {
            fseek(file, indexTable[i].position * sizeof(struct Record), SEEK_SET);
            fread(&rec, sizeof(rec), 1, file);
            printf("Record found: ID: %d, Name: %s\n", rec.id, rec.name);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Record not found!\n");
    }
    
    fclose(file);
}

// Main function
int main() {
    int choice;
    
    while (1) {
        printf("\n1. Create Indexed File\n2. Search Indexed File\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createIndexedFile();
                break;
            case 2:
                searchIndexedFile();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
