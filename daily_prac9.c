#include<stdio.h>
#include<stdlib.h>
 void factors(int arr[],int m) {
   int j=0;
   for(int i=2;m!=1;) {
       if(m%i==0) {
         arr[j++]=i; m=m/i;
        } else i++;
    }
}
void main() {
 int m,n,c=0,gcd=1,mul=1;
  printf("Enter m and n: ");
  scanf("%d%d",&m,&n);
  int min=(m<n)?m:n;
  int arr1[100]={0},arr2[100]={0};
  factors(arr1,m);
  factors(arr2,n);
  for(int i=0;arr1[i]!=0;i++) {
    if(arr1[i]==-1)
       continue;
   for(int j=0;arr2[j]!=0;j++) {
     c++;
    if(arr2[j]==-1)
      continue;
    if(arr1[i]==arr2[j]) {
      mul=mul*arr1[i];
      arr1[i]=arr2[j]=-1;
     }
   }
 }
 printf("Opcount: %d\n",c);
 printf("GCD: %d\n",mul);
 printf("the sum is %d", m+n);
}
