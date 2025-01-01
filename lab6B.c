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

void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack\n", value);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
    } else {
        struct Node* temp = *top;
        *top = (*top)->next;
        printf("%d popped from the stack\n", temp->data);
        free(temp);
    }
}

void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = createNode(value);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued into the queue\n", value);
}

void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue underflow\n");
    } else {
        struct Node* temp = *front;
        *front = (*front)->next;
        if (*front == NULL) {
            *rear = NULL;
        }
        printf("%d dequeued from the queue\n", temp->data);
        free(temp);
    }
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        while (top != NULL) {
            printf("%d -> ", top->data);
            top = top->next;
        }
        printf("NULL\n");
    }
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents: ");
        while (front != NULL) {
            printf("%d -> ", front->data);
            front = front->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* stackTop = NULL;
    struct Node *queueFront = NULL, *queueRear = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push (Stack)\n2. Pop (Stack)\n3. Display Stack\n4. Enqueue (Queue)\n5. Dequeue (Queue)\n6. Display Queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push onto the stack: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;
            case 2:
                pop(&stackTop);
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                printf("Enter value to enqueue into the queue: ");
                scanf("%d", &value);
                enqueue(&queueFront, &queueRear, value);
                break;
            case 5:
                dequeue(&queueFront, &queueRear);
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!!!\n");
        }
    }
   return 0;
}
