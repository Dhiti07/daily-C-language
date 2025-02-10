#include <stdio.h>
#define MAX 10
int adj_mat[MAX][MAX];
int in_degree[MAX];
int toposort[MAX];
int n;
int opcount = 0;
void toposort_source_removal() {
    int topoindex = 0;
    for (int i = 0; i < n; i++) {
        in_degree[i] = 0;
        toposort[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_mat[j][i] == 1) {
                in_degree[i]++;
            }
        }
    }
    while (1) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                opcount++;
                toposort[topoindex++] = i;
                in_degree[i] = -1;
                found = 1;
                for (int j = 0; j < n; j++) {
                    if (adj_mat[i][j] == 1) {
                        in_degree[j]--;
                    }
                }
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    if (topoindex < n) {
        printf("Graph contains a cycle. Topological sorting not possible.\n");
        return;
    }
    printf("Topological Sort (Source Removal): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", toposort[i]);
    }
    printf("\n");
}
int main() {
    int m;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_mat[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v) where u -> v is an edge:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj_mat[u][v] = 1;
        } else {
            printf("Invalid edge: %d -> %d\n", u, v);
        }
    }
    toposort_source_removal();
    printf("The opcount is %d\n", opcount);
    return 0;
}
