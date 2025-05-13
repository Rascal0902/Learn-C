#include<iostream>
#include "Stack.h"
#include<stdio.h>
int main(){
     char str[10] = {'(',')','(','(',')',')','(',')',')',')' };

     Stack* s = create();
     for (int i = 0; i < 10; i++){
            if (str[i] == '('){
                    push(s,0);
                }
            else{
                printf("%d",peek(s));
                if(peek(s) != 0){
                    printf("false");
                    return 0;
                }
                pop(s);
            }

     }
     printf("true");

    return 0;
}
