#include<stdio.h>

int attend[31] = { 0, };

int main() {
	int Me;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &Me);
		attend[Me] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (attend[i] == 0)printf("%d\n", i);
	}
	return 0;
}