#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define MAX_KEYS 10

struct Employee {
    int key;
    char name[50];
};

int linearProbing(int hashTable[], int m, int index) {
    int i = index;
    while (hashTable[i] != -1) {
        i = (i + 1) % m;  
        if (i == index) {
            return -1;  
        }
    }
    return i;
}

int hashFunction(int key, int m) {
    return key % m;
}

void insert(int hashTable[], struct Employee employees[], int key, int m, int *size) {
    int index = hashFunction(key, m);  
    if (hashTable[index] == -1) {
        hashTable[index] = key;
        employees[index].key = key;
        printf("Enter employee name: ");
        scanf("%s", employees[index].name);
        (*size)++;
        printf("Employee with key %d inserted at index %d.\n", key, index);
    } else {
        int newIndex = linearProbing(hashTable, m, index);
        if (newIndex != -1) {
            hashTable[newIndex] = key;
            employees[newIndex].key = key;
            printf("Enter employee name: ");
            scanf("%s", employees[newIndex].name);
            (*size)++;
            printf("Employee with key %d inserted at index %d.\n", key, newIndex);
        } else {
            printf("No available space to insert the record.\n");
        }
    }
}




int search(int hashTable[],  int key, int m) {
    int index = hashFunction(key, m);  
    if (hashTable[index] == key) {
        return index;  
    } else {
        int i = (index + 1) % m;
        while (i != index) {
            if (hashTable[i] == key) {
                return i;  
            }
            i = (i + 1) % m;
        }
    }
    return -1; 
}

void display(int hashTable[], struct Employee employees[], int m) {
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1) {
            printf("Employee Key: %d, Name: %s at index %d\n", employees[i].key, employees[i].name, i);
        }
    }
}

int main() {
    int m, size = 0;
    
    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);
    
    int hashTable[m];  
    struct Employee employees[m];  

    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }
    
    while (1) {
        int choice, key;
        
        printf("\n1. Insert Employee\n2. Search Employee\n3. Display Employees\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter employee key (4-digit): ");
                scanf("%d", &key);
                insert(hashTable, employees, key, m, &size);
                break;
            case 2:
                printf("Enter employee key to search: ");
                scanf("%d", &key);
                int index = search(hashTable, key, m);
                if (index != -1) {
                    printf("Employee with key %d found at index %d. Name: %s\n", key, index, employees[index].name);
                } else {
                    printf("Employee with key %d not found.\n", key);
                }
                break;
            case 3:
                display(hashTable, employees, m);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
