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

void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("List is already sorted or empty\n");
        return;
    }
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted\n");
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed\n");
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
    }
    *head2 = NULL;
    printf("Lists concatenated\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert into List 1\n2. Insert into List 2\n3. Sort List 1\n4. Reverse List 1\n5. Concatenate Lists\n6. Display List 1\n7. Display List 2\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into List 1: ");
                scanf("%d", &value);
                insertAtEnd(&list1, value);
                break;
            case 2:
                printf("Enter value to insert into List 2: ");
                scanf("%d", &value);
                insertAtEnd(&list2, value);
                break;
            case 3:
                sortList(&list1);
                break;
            case 4:
                reverseList(&list1);
                break;
            case 5:
                concatenateLists(&list1, &list2);
                break;
            case 6:
                displayList(list1);
                break;
            case 7:
                displayList(list2);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!!!\n");
        }
    }
    return 0;
}
