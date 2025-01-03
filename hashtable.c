#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of employees
#define SIZE 10  // Size of the hash table (m)

typedef struct {
    int key;   // Employee key (4-digit)
    char name[50];  // Employee name
} Employee;

// Hash table definition
int hashTable[SIZE];  // Array to store hash table
Employee empRecords[MAX];  // Array to store employee records

// Initialize hash table with -1 (indicating empty slots)
void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // -1 indicates that the slot is empty
    }
}

// Hash function to map keys to addresses in hash table
int hashFunction(int key) {
    return key % SIZE;  // H(K) = K mod m
}

// Linear probing to resolve collision
int linearProbing(int key) {
    int index = hashFunction(key);
    
    // Linear probing: Check for next available spot
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;  // Wrap around using modulo
    }
    
    return index;  // Return the found empty index
}

// Function to insert an employee record into the hash table
void insertEmployee(int key, char name[]) {
    int index = hashFunction(key);
    
    if (hashTable[index] == -1) {
        hashTable[index] = key;  // Direct insertion if no collision
    } else {
        // Resolve collision using linear probing
        index = linearProbing(key);
        hashTable[index] = key;
    }
    
    // Find the index of the employee's record and store it
    for (int i = 0; i < MAX; i++) {
        if (empRecords[i].key == 0) {
            empRecords[i].key = key;
            snprintf(empRecords[i].name, sizeof(empRecords[i].name), "%s", name);
            break;
        }
    }
}

// Function to display the hash table
void displayHashTable() {
    printf("\nHash Table (HT):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] != -1) {
            printf("%d\n", hashTable[i]);
        } else {
            printf("Empty\n");
        }
    }
}

// Function to search for an employee by key
void searchEmployee(int key) {
    int index = hashFunction(key);
    int startIndex = index;  // To avoid infinite loop in case of full table

    // Linear probing for search
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            // Find and print the employee record
            for (int i = 0; i < MAX; i++) {
                if (empRecords[i].key == key) {
                    printf("Employee Found: Key = %d, Name = %s\n", empRecords[i].key, empRecords[i].name);
                    return;
                }
            }
        }
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            break;  // If we looped back to the start index, the table is full
        }
    }

    printf("Employee with Key %d not found.\n", key);
}

// Main function to drive the program
int main() {
    initializeHashTable();
    
    // Inserting employee records
    insertEmployee(1234, "Alice");
    insertEmployee(5678, "Bob");
    insertEmployee(9101, "Charlie");
    insertEmployee(1122, "David");
    insertEmployee(3344, "Eve");
    insertEmployee(5566, "Frank");
    
    // Displaying the hash table after insertions
    displayHashTable();
    
    // Searching for an employee
    searchEmployee(1234);
    searchEmployee(5566);
    searchEmployee(9999);  // Non-existing employee key

    return 0;
}
