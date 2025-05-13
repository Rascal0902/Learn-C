#include <stdio.h>


int main() {

	int a, b;

	while (scanf("%d %d", &a, &b) != -1) {
		printf("%d \n", a + b);
	}
    //읽은 데이터 개수에 따른 반환 값
	return 0;
}