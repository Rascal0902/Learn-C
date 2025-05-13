#include<stdio.h>
#include<string.h>
int N, Re;
char a[21];
int main(){
     scanf("%d",&N);
     while(N--){
        scanf("%d %s",&Re,a);
        for(int i=0;i<strlen(a);i++){
            for(int j=0;j<Re;j++){
                printf("%c",a[i]);
            }
        }
        printf("\n");
     }
}