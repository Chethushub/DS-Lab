#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

void insert(int queue[], int *front, int *rear) {
    int item;
    if ((*rear + 1) % QUEUE_SIZE == *front) {
        printf("Queue overflow\n");
    } else {
        printf("\nEnter an item: ");
        scanf("%d", &item);
        if (*front == -1) {
            *front = 0;
        }
        *rear = (*rear + 1) % QUEUE_SIZE;
        queue[*rear] = item;
        printf("%d inserted into the queue\n", item);
    }
}

void delete(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\n%d deleted from the queue\n", queue[*front]);
        if (*front == *rear) {
            *front = *rear = -1; // Reset queue if empty
        } else {
            *front = (*front + 1) % QUEUE_SIZE;
        }
    }
}

void display(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = *front;
        while (1) {
            printf("%d\t", queue[i]);
            if (i == *rear) {
                break;
            }
            i = (i + 1) % QUEUE_SIZE;
        }
        printf("\n");
    }
}

int main() {
    int queue[QUEUE_SIZE], front = -1, rear = -1, choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(queue, &front, &rear); break;
            case 2: delete(queue, &front, &rear); break;
            case 3: display(queue, &front, &rear); break;
            case 4: exit(0); break;
            default: printf("Invalid choice!!!\n"); break;
        }
    }
    return 0;
}
