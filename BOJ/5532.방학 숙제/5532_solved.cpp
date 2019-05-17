#include<stdio.h>

int main() {
	int L, A, B, C, D;
	scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);
	int day;
	if (A / C > B / D) {
		day = A / C;
		if (A%C != 0)day++;
	}
	else {
		day = B / D;
		if (B%D != 0)day++;
	}
	printf("%d", L - day);
}