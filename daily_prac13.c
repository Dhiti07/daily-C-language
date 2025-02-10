#include<stdio.h>
#include<limits.h>
#define MAX_N 10
int calculate_cost(int cost_matrix[MAX_N][MAX_N], int perm[MAX_N], int n){
 int total_cost = 0;
 for(int i=0;i<n;i++){
  total_cost+=cost_matrix[i][perm[i]];
 }
 return total_cost;
}
void generate_perm(int arr[MAX_N], int n, int start, int cost_matrix[MAX_N][MAX_N],int*min_cost, int perm[MAX_N]){
 if(start==n){
    int current_cost = calculate_cost(cost_matrix, arr, n);
    if(current_cost<*min_cost){
        *min_cost= current_cost;
        for(int i=0;i<n;i++){
            perm[i] = arr[i];
        }
    }
    return;
 }
 for(int i=start;i<n;i++){
 int temp = arr[start];
 arr[start] = arr[i];
 arr[i] = temp;
 generate_perm(arr,n,start+1,cost_matrix, min_cost,perm);
 temp = arr[start];
 arr[start]=arr[i];
 arr[i] = temp;
 }
}
int main(){
 int n;
 printf("enter the no. of workers");
 scanf("%d",&n);
 int cost_matrix[MAX_N][MAX_N];
 printf("enter the cost of the matrix:\n");
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&cost_matrix[i][j]);
    }
 }
 int arr[MAX_N];
 int perm[MAX_N];
 for(int i=0;i<n;i++){
    arr[i] = i;
 }
 int min_cost = INT_MAX;
 generate_perm(arr,n,0,cost_matrix,&min_cost,perm);
 printf("\nMinimum cost: %d\n",min_cost);
 printf("optimal assignment:\n");
 for(int i=0;i<n;i++){
    printf("worker %d -> task %d\n",i+1,perm[i]+1);
 }
 return 0;
}

