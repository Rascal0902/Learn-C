#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct Student{
    int id;
} student;

int main(){
    student a;
    a.id = 10;
    printf("%d", a.id);
}
