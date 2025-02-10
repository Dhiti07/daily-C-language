#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int opcount = 0;
int stack[MAX];
int top = -1;
int graph[MAX][MAX];
int visited[MAX];

void push(int v) {
    if (top < MAX - 1) {
        stack[++top] = v;
    } else {
        printf("Stack overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

void DFS(int start, int n) {
    int current;

    push(start);
    visited[start] = 1;

    printf("Push order: %d\n", start);

    while (top != -1) {
        current = pop();
        printf("Pop order: %d\n", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                opcount++;
                push(i);
                printf("Push order: %d\n", i);
            }
        }
    }
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
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal:\n");
    DFS(0, n);

    printf("Operation count is %d\n", opcount);

    return 0;
}
