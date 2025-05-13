#include "Deque.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char* str) {
    int len = strlen(str);
    Deque *dq = create();
    for (int i = 0; i < len; i++) {
            addRear(dq, str[i]);
    }
    while (size(dq) > 1) {
            char frontChar = deleteFront(dq);
            char rearChar = deleteRear(dq);
            if (frontChar != rearChar) {
                 return false;
            }
    }

    return true;
}

int main() {
    bool result;
    char my_str1[100] = "asdfasdfasdfasdf";
    printf("%s ", my_str1);
    result = isPalindrome(my_str1);
    printf("%s", result? "is palindrome\n":"is not palindrome\n");
    char my_str2[100] = "ABCDEFASDADADA";
    printf("%s ", my_str2);
    result = isPalindrome(my_str2);
    printf("%s", result? "is palindrome\n":"is not palindrome\n");
    return 0;
}
