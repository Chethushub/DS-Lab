#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void dfs(int graph[MAX][MAX], int visited[MAX], int vertex, int n) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}

int main() {
    int graph[MAX][MAX], visited[MAX], n, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(graph, visited, startVertex, n);
    printf("\n");
    return 0;
}

