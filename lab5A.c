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
    printf("%d inserted into the list\n", value);
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("%d deleted from the list (first element)\n", temp->data);
        free(temp);
    }
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->next == NULL) { // Only one element
        printf("%d deleted from the list (last element)\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("%d deleted from the list (last element)\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteElement(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->data == value) {
        deleteFirst(head);
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("%d not found in the list\n", value);
        } else {
            prev->next = temp->next;
            printf("%d deleted from the list (specified element)\n", temp->data);
            free(temp);
        }
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
    int choice, value;

    while (1) {
        printf("\n1. Create (Insert at end)\n2. Delete first element\n3. Delete last element\n4. Delete specified element\n5. Display list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                deleteFirst(&head);
                break;
            case 3:
                deleteLast(&head);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(&head, value);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!!!\n");
        }
    }
   return 0;
}
