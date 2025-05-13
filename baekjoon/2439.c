#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    for(int i=N-1;i>=0;i--){
        for(int j=1;j<=i;j++){
            printf(" ");
        }
        for(int j=1;j<=N-i;j++){
            printf("*");
        }
        printf("\n");
    }
}