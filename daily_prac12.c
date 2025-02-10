#include<stdio.h>
#include<stdlib.h>
int subsetsum(int arr[], int n,int mask){
 int sum =0;
 for(int i=0;i<n;i++){
 if(mask & (1<<i)){
  sum+=arr[i];
 }
}
return sum;
}
int isPartionPossible(int arr[], int n){
 int total = 0;
 for(int i=0;i<n;i++){
  total+=arr[i];
 }
 if(total%2!=0)
 return 0;
 int target = total/2;
 for(int mask = 1;mask<(1<<n);mask++){
   if(subsetsum(arr,n,mask)== target)
      return 1;
 }
 return 0;
}
int main(){
 int n;
 printf("enter the no. of elements");
 scanf("%d",&n);
 int arr[n];
 printf("enter the no. of elements in the array");
 for(int i=0;i<n;i++){
   scanf("%d",&arr[i]);
 }
 if(isPartionPossible(arr,n))
  printf("Partition exists\n");
 else
  printf("partion doesn't exists");
return 0;
}
