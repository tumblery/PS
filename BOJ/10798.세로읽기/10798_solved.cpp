#include<stdio.h>
char input[5][15] = { 0, };

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%s", input[i]);
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (input[j][i] == 0)continue;
			printf("%c", input[j][i]);
		}
	}
	return 0;
}