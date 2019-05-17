#include<stdio.h>

int main() {
	int list[4];//A, B, C, D;
	int X, Y;
	int P;
	for (int i = 0; i < 4; i++)
		scanf("%d", &list[i]);
	scanf("%d", &P);
	X = P*list[0];
	Y = list[1];
	if (P > list[2]) {
		P -= list[2];
		Y += P*list[3];
	}

	printf("%d", X < Y ? X : Y);
}