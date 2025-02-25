#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
int opcount = 0;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}
Node* findLCA(Node* root, int n1, int n2) {
    while (root != NULL) {
        opcount++;
        if (root->data > n1 && root->data > n2) {
            root = root->left;
        } else if (root->data < n1 && root->data < n2) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}
int main() {
    Node* root = NULL;
    int n, data, n1, n2;
    printf("Enter the number of nodes you want to insert in the binary search tree: ");
    scanf("%d", &n);
    printf("Enter the values of the nodes (one by one):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    printf("Enter two nodes to find their Lowest Common Ancestor (LCA): ");
    scanf("%d %d", &n1, &n2);
    Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("The Lowest Common Ancestor of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("No common ancestor found.\n");
    }
    printf("Number of operations performed (opcount): %d\n", opcount);
    return 0;
}
