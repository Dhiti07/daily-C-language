#include<stdio.h>
void roll(int arr[],int x){
    int sum =0;
    for(int i=0;i<x;i++){
        sum= sum+arr[i];
    }
    display(sum);
}
void display(int y){
    printf("the sum = %d",y);
}

int main(){
    char name[100][100],topperN[100][100];
    int roll_no[100], marks[100],topperR[100];
    int n;
    printf("enter the no. of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the details of %d student: ",i+1);
        scanf("%s",name[i]);
        scanf("%d",&roll_no[i]);
        scanf("%d",&marks[i]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(marks[i]>90){
           strcpy(topperN[count],name[i]);
           topperR[count]=roll_no[i];
           count++;
        }
    }
    for(int i=0;i<count;i++){
        for(int j=0;j<count;j++){
            if(topperR[j]<topperR[i]){
                int temp;
                temp=topperR[j];
                topperR[j]=topperR[i];
                topperR[i]=temp;
                char str[100];
                strcpy(str,topperN[j]);
                strcpy(topperN[j],topperN[i]);
                strcpy(topperN[i],str);
            }
        }
    }
    for(int i=0;i<count;i++){
        printf("The students who scored above 90: %s \n",topperN[i]);
        printf("The roll no. of those students are: %d\n",topperR[i]);
    }
    printf("the sorted list of roll no. are: ",topperR);
    roll(topperR,n);
}
