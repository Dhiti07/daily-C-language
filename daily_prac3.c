//daily practice problem 3
#include<stdio.h>
#include<string.h>
int add(int x[100]){
    int sum=0;
    for(int i=1;i<=5;i++){
        sum+=x[i];
    }
    return sum;
}
   int main(){
    char y;
    char names[100][100]={};
    int m,a;
    int z[10];
    printf("Choose any one option among A or B: ");
    scanf("%ch",&y);
    if(y=='A'){
        for(int j=1;j<=5;j++){
            printf("enter names: ");
            scanf("%ch",&names[j]);
        }
    }
    else {
        for(int k=1;k<=5;k++){
            printf("enter the no.: ");
            scanf("%d",&z[k]);
        }
        int m=add(z);
        a= m%100;
        printf("your sum is: %d\n",m);
        printf("your last 2 digits are: %d",a);
    }
return 0;
}

