#include <stdio.h>
#include <string.h>


int main() {

	
	int t;
	char s[80];
	int score;
	int oCnt;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%s", s);
		
		score = 0;
		oCnt = 1;

		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == 'O') score += oCnt++;
			else if (s[i] == 'X') oCnt = 1;
		}

		printf("%d \n", score);
	}


	return 0;
}