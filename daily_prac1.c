//practice problem 1
#include<stdio.h>
int main(){
    int n,max_alt,gain,max;
    printf("enter the no. of times altitude changes: ");
    scanf("%d",&n);
    max = 0;
    gain = 0;
    max_alt =0;
    for(int i=1;i<=n;i++){
        printf("enter the gain: ");
        scanf("%d",&gain);
        max=max+gain;
        if (max>max_alt){
            max_alt=max;
        }
    }
    printf("the highest altitude the biker covered: %d",max_alt);
return 0;
}
