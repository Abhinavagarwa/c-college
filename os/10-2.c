#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

// Structure to represent a record in the file
struct Record {
    int id;                  // Unique ID for each record
    char name[20];          // Name associated with the ID
};

// Hash function to determine file index based on the record's id
int hashFunction(int id) {
    return id % MAX_RECORDS;
}

// Function to insert a record using hashed organization with linear probing
void insertRecord() {
    FILE *file = fopen("hashed.dat", "rb+");
    if (!file) {
        file = fopen("hashed.dat", "wb+"); // Create file if it doesn't exist
    }
    struct Record rec, temp;
    int index, originalIndex;

    printf("Enter ID and Name: ");
    scanf("%d %s", &rec.id, rec.name);
    
    index = hashFunction(rec.id);
    originalIndex = index;  // Store the original index

    // Collision handling using linear probing
    while (1) {
        fseek(file, index * sizeof(struct Record), SEEK_SET);
        fread(&temp, sizeof(struct Record), 1, file);

        if (temp.id == 0) {  // Empty slot
            fseek(file, index * sizeof(struct Record), SEEK_SET);
            fwrite(&rec, sizeof(struct Record), 1, file);
            printf("Record inserted successfully at index %d!\n", index);
            break;
        } else {
            // Collision occurred, check the next index
            index = (index + 1) % MAX_RECORDS; // Wrap around
            if (index == originalIndex) {
                printf("Table is full! Record not inserted.\n");
                break;
            }
        }
    }

    fclose(file);
}

// Function to display records in the hashed file
void displayHashedFile() {
    FILE *file = fopen("hashed.dat", "rb");
    struct Record rec;

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("ID\tName\n");
    printf("-------------------\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        fseek(file, i * sizeof(struct Record), SEEK_SET);
        fread(&rec, sizeof(struct Record), 1, file);
        if (rec.id != 0) {  // Only display non-empty records
            printf("%d\t%s\n", rec.id, rec.name);
        }
    }

    fclose(file);
}

// Main function
int main() {
    int choice;

    // Initialize the hashed file to ensure all records are empty
    FILE *initFile = fopen("hashed.dat", "wb");
    if (initFile) {
        struct Record emptyRecord = {0, ""}; // Initialize an empty record
        for (int i = 0; i < MAX_RECORDS; i++) {
            fwrite(&emptyRecord, sizeof(struct Record), 1, initFile);
        }
        fclose(initFile);
    }

    while (1) {
        printf("\n1. Insert Record\n2. Display Records\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRecord();
                break;
            case 2:
                displayHashedFile();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

