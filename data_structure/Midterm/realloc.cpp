#include <stdio.h>
#include <stdlib.h>
int main(){
 int *arr = (int *)malloc(sizeof(int) * 5);
 printf("%p\n"
, arr);
 int *arr_ = (int *)realloc(arr, sizeof(int) * 10000);
 //int *arr_ = realloc(arr, sizeof(int) * 100);
 printf("%p\n"
, arr_);
 //arr = NULL;
 printf("%d\n"
, arr[4]);
 arr_ = NULL;
 return 0;
}
