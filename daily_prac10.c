void bubblesort(int arr[], int n){
 int temp;
 int opcount = 0;
 for(int i=0;i<n-1;i++){
  for(int j=0;j<n-i-1;j++){
    if(arr[j]>arr[j+1]){
      ++opcount;
      temp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = temp;
    }
  }
 }
 printf("opcount is %d", opcount);
 printf("printing the sorted array: \n");
 for(int i=0;i<n;i++){
  printf("element no %d is %d\n",i,arr[i]);
 }
}
int main(){
 int n;
 printf("enter no. of elements");
 scanf("%d",&n);
 int arr[n];
 printf("enter elements");
 for(int i=0;i<n;i++){
  scanf("%d", &arr[i]);
 }
 bubblesort(arr,n);
 return 0;
}
