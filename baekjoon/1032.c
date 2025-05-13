#include<stdio.h>
#include<string.h>
int n;
char a[100],b[100];
int main(){
   scanf("%d",&n);
   for(int i=n;i>=1;i--){
    if(i == n){
    scanf("%s",a);
    }
    else{
        scanf("%s",b);
        for(int j=0;j<strlen(b);j++)
        {
            if(a[j]!=b[j]){
                a[j]='?';
            }
        }
    }
   }
   for(int i=0;i<strlen(a);i++){
    printf("%c",a[i]);
   }
}