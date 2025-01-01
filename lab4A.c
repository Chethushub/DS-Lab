#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the beginning\n", value);
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end\n", value);
}

void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("%d inserted at position %d\n", value, position);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("%d inserted at position %d\n", value, position);
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        printf("Linked list contents: ");
        while (head != NULL) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Display list\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!!!\n");
        }
    }
}
