//daily practice problem 6
#include<stdio.h>
#include<string.h>
void sum(int arr[10]){
    int odd_sum=0;
    int even_sum=0;
    for(int i=0;i<10;i++){
        if(arr[i]%2!=0){
            odd_sum=odd_sum+arr[i];
        }
        else{
            even_sum = even_sum+arr[i];
        }
    }
    printf("your odd sum is: %d \n",odd_sum);
    printf("your even sum is: %d",even_sum);
    return;
}
int main(){
    int x;
    printf("select choice among 1,2,3: ");
    scanf("%d",&x);
    if(x==1){
       int n,sum=0;
       int arr[n][n];
       printf("enter the order of matrix: ");
       scanf("%d",&n);
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               printf("enter the elements: ");
               scanf("%d",&arr[i][j]);
        }
    }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("arr[%d][%d] =%d ",i,j,arr[i][j]);
            }
            printf("\n");
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                   sum=sum+arr[i][j];
            }
         }
    }
         printf("your sum is: %d",sum);
    }
    else if (x==2){
        char str[100];
        int count=0;
        printf("enter your string: ");
        scanf("%s",&str);
        for(int i=0;i<100;i++){
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
                count++;
            }
        }
        printf("the total no. of vowels are: %d",count);
    }
    else if (x==3){
        int arr[10];
        for(int i=0;i<10;i++){
            printf("enter nos. : ");
            scanf("%d",&arr[i]);
        }
        sum(arr);
      }
return 0;
}
