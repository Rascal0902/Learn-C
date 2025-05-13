#include<stdio.h>
int a[100]={0},N=1; 
int main(){
   int t;
   for(int i=0;i<3;i++){
     scanf("%d",&t);
     N*=t;
   }
   int temp;
   for(int i=1;;i++){
     temp = N%10;
     a[temp]++;
     if(N<10){
        break;
     }
     N /= 10;
   }
   for(int i=0;i<=9;i++){
     printf("%d\n",a[i]);
   }
}