#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Structure to represent a record in the file
struct Record {
    int id;
    char name[20];
};

// Function to create a new sequential file
void createFile() {
    FILE *file = fopen("sequential.dat", "wb");
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
    }
    
    fclose(file);
    printf("File created successfully!\n");
}

// Function to display records in the file
void displayFile() {
    FILE *file = fopen("sequential.dat", "rb");
    struct Record rec;
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("ID\tName\n");
    printf("-------------------\n");
    while (fread(&rec, sizeof(rec), 1, file)) {
        printf("%d\t%s\n", rec.id, rec.name);
    }
    
    fclose(file);
}

// Main function
int main() {
    int choice;
    
    while (1) {
        printf("\n1. Create File\n2. Display File\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                displayFile();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
