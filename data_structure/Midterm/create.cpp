#include<stdio.h>
#include<stdlib.h>
typedef struct {
 int* id;
 int midterm;
 int final;
 int attendance;
 int assignment;
} Student;
int main(){
 Student *a;
 printf("%p\n",a);
 Student student_array[90];
 printf("Size of int type : %lu Bytes\n"
, sizeof(unsigned long));
 printf("Size of Student type : %lu Bytes\n"
, sizeof(Student));
 printf("Size of student_array : %lu Bytes\n"
, sizeof(student_array));
 printf("Value of student_array : %p\n"
, student_array);
 printf("Address of student_array[0] : %p\n", &student_array[0]);
 printf("Address of student_array[0].id : %p\n", &student_array[0].id);
 Student *student_ptr = (Student *) malloc(sizeof(Student) * 90);
 printf("Initial midterm score of the first student : %d\n"
,student_ptr[0].midterm);
 free(student_ptr);
 // free(student_array); // error
 return 0;
}
