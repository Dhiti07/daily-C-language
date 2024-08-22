//daily practice problem 4
#include<stdio.h>
int hero(int n[100],int j){
    int x = 1;
    int i=0;
    while(i<j){
        x=x*n[i];
        i++;
    }
    return x;
}
int rev(int z){
     int rev,last;
     rev=0;
     while(z!=0){
         last = z%10;
         if(last==0)
         {
         rev=rev*100;}
         else{
         rev = rev*10+last;
         }
         z=z/10;
    }
    return rev;
}
int main(){
    int num[10];
    for(int i=0;i<10;i++){
        printf("enter the nos. for array: ");
        scanf("%d",&num[i]);
    }
    int mul;
    mul=hero(num,10);
    //int a =123;
    int reversed=rev(mul);
    printf("your multiplied value is: %d",mul);
    printf("your reversed value is: %d",reversed);
return 0;
}
