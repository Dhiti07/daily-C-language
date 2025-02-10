#include<stdio.h>
#include<string.h>
int main(){
 int opcount = 0;
 int t;
 char par[50];
 char child[50];
 printf("enter the main string");
 scanf("%s", par);
 printf("enter the substring");
 scanf("%s",child);
 int n = strlen(par);
 int m = strlen(child);
 for(int i=0;i<=n-m;i++){
  int j=0;
  while(j<m&&child[j]== par[i+j]){
   opcount++;
   j++;
   if(j=m){
    printf("opcount is %d\n",opcount);
    printf("the string matches from %d index",i);
    t=1;
   }
  }
 }
 if(t=0){
  printf("the string doesn't match");
 }
 printf("substring: %d\n",m);
 return 0;
}
