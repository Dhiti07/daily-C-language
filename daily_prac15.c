#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int opcount = 0;
int queue[MAX];
int front = -1, rear = -1;
int graph[MAX][MAX];
int visited[MAX];

void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = v;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int value = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return value;
    }
}

void BFS(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;
    opcount++;

    printf("BFS starting from vertex %d: ", start);

    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                opcount++;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    BFS(0, n);
    printf("Operation count is %d\n", opcount);

    return 0;
}
