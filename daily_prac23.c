#include<stdio.h>
void merge(int arr[],int l, int mid, int h){
 int temp[h-l+1];
 int i = l;
 int j = mid+1;
 int k =0;

 while(i<=mid && j<=h){
    if(arr[i]<arr[j]){
        temp[k] = arr[i];
        i++;
    }
    else{
        temp[k]=arr[j];
        j++;
    }
    k++;
 }
 while(i<=mid){
    temp[k++]=arr[i++];
 }
 while(j<=h){
    temp[k++]=arr[j++];
 }
 i=l;
 int c=k;
 for(k =0;k<c;k++){
    arr[i]=temp[k];
    i++;
 }
}
void mergesort(int arr[],int l,int h){
  if(l<h){
    int mid = l+ (h-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,h);
    merge(arr,l,mid,h);
  }
}
int main(){
 int n;
 printf("enter the no. of elements");
 scanf("%d",&n);
 int arr[n];
 printf("enter the elements");
 for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
 mergesort(arr,0,n-1);
 for(int i=0;i<n;i++){
    printf("%d",arr[i]);
 }
}
