// daily practice problem 2
#include<stdio.h>
int main(){
    int n,E,N;
    E==0,N==0;
    char dir;
    printf("enter no. of steps raju walks: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("enter the direction: ");
        scanf("%ch"W,&dir);
        if(dir=='U')
           N++;
        else if(dir=='D')
           N--;
        else if(dir=='R')
           E++;
        else if(dir=='L')
           E--;
    }
    if(E==0&& N==0){
        printf("Raju is it's actual position");
    }
    else{
        printf("Raju is not at it's actual position");
    }
return 0;
}
