#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Define the size of the hash table

// Function prototypes
void insert(int hashTable[], int size, int key);
int search(int hashTable[], int size, int key);
void display(int hashTable[], int size);

// Secondary hash function for double hashing
int secondaryHashFunction(int key, int size) {
    return 7 - (key % 7);  // A prime number smaller than the table size
}

// Main hash function H(K) = K mod size
int hashFunction(int key, int size) {
    return key % size;
}

// Insert a key into the hash table using double hashing
void insert(int hashTable[], int size, int key) {
    int index = hashFunction(key, size);  // Primary hash
    int stepSize = secondaryHashFunction(key, size);  // Secondary hash
    int originalIndex = index;
    int i = 0;

    // Resolve collisions using double hashing
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Product Code %d already exists in the hash table.\n", key);
            return;  // Key already exists
        }
        i++;
        index = (originalIndex + i * stepSize) % size;

        if (i >= size) {
            printf("Hash table is full! Cannot insert %d.\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Product Code %d inserted at index %d.\n", key, index);
}

// Search for a key in the hash table using double hashing
int search(int hashTable[], int size, int key) {
    int index = hashFunction(key, size);  // Primary hash
    int stepSize = secondaryHashFunction(key, size);  // Secondary hash
    int originalIndex = index;
    int i = 0;

    // Search using double hashing
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;  // Key found
        }
        i++;
        index = (originalIndex + i * stepSize) % size;

        if (i >= size) {
            break;
        }
    }

    return -1;  // Key not found
}

// Display the hash table
void display(int hashTable[], int size) {
    printf("\nHash Table:\n");
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: [Empty]\n", i);
        }
    }
}

// Main function
int main() {
    int hashTable[TABLE_SIZE];
    int choice, key;

    // Initialize the hash table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    while (1) {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert a Product Code\n");
        printf("2. Search for a Product Code\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product Code to Insert: ");
                scanf("%d", &key);
                insert(hashTable, TABLE_SIZE, key);
                break;

            case 2:
                printf("Enter Product Code to Search: ");
                scanf("%d", &key);
                if (search(hashTable, TABLE_SIZE, key) != -1) {
                    printf("Product Code %d found in the hash table.\n", key);
                } else {
                    printf("Product Code %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                display(hashTable, TABLE_SIZE);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
