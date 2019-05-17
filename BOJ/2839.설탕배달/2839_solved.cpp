#include<stdio.h>

int list[5001];
int min(int a, int b) {
	return a < b ? a : b;
}
int solve(int n) {
	if (list[n] != 0)return list[n];
	if (n < 3&&n>0)return list[n] = -1;
	if (n < 5&&n>3)return list[n] = -1;	
	int a = solve(n - 3);
	int b = solve(n - 5);
	if (a == -1 && b == -1) {
		return list[n] = -1;
	}
	else if (a != -1 && b == -1) {
		return list[n] = a + 1;
	}
	else if (a == -1 && b != -1) {
		return list[n] = b + 1;
	}
	else {
		list[n] = min(a + 1, b + 1);
	}
	return list[n];
}
int main() {
	int N;
	scanf("%d", &N);
	list[3] = 1;
	list[5] = 1;
	list[0] = 0;
	printf("%d",solve(N));
	return 0;
}