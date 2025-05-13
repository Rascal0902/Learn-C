#include <stdio.h>

int main()
{
    int a_divisor = 0; //약수를 입력받을 변수
    long long max = 0, min = 1000001; //입력받은 약수중 최대값과 최소값을 각각 저장할 변수

    int num_of_divisors; //약수의 개수를 저장할 변수
    scanf("%d", &num_of_divisors);

    for(int i = 0; i < num_of_divisors; i++){ //약수의 개수만큼 약수를 입력받으며 
        scanf("%d", &a_divisor);

        if(a_divisor > max)                 //그중 최대값과 최소값을 찾는다.
            max = a_divisor;
        if(a_divisor < min)
            min = a_divisor;
    }

    printf("%lld\n", max * min);

    return 0;
}