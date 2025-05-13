#include<stdio.h>
int a[10],max=0,t=0;
int main(){
   for(int i=0;i<9;i++){
      scanf("%d",&a[i]);
   }
   for(int i=0;i<9;i++){
      if(max<a[i]){
         max = a[i];
         t = i;
      }
   }
   printf("%d\n%d",max,t+1);
}