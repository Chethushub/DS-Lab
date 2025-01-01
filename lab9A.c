#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return value;
    }
}

void bfs(int graph[MAX][MAX], int startVertex, int n) {
    struct Queue q;
    initQueue(&q);
    int visited[MAX] = {0}; 

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);
    
    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX], n, startVertex;
    

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    bfs(graph, startVertex, n);
    return 0;
}

