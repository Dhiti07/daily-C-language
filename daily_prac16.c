#include <stdio.h>
#define MAX_VERTICES 10
int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int topoSort[MAX_VERTICES];
int n;
int topoIndex = 0;
int opcount = 0;
void DFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        opcount++;
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
    topoSort[n - 1 - topoIndex] = v;
    topoIndex++;
}
void topologicalSortDFS() {
    topoIndex = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    printf("Topological Sort (DFS): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", topoSort[i]);
    }
    printf("\n");
}
int main() {
    int m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v) where u -> v is an edge:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
        } else {
            printf("Invalid edge: %d -> %d\n", u, v);
        }
    }
    topologicalSortDFS();
    printf("The opcount is %d\n", opcount);
    return 0;
}
