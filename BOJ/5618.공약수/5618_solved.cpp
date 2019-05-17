#include<stdio.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int input[3];
	int N,M=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		M = max(M, input[i]);
	}
	for (int i = 1; i <= M; i++) {
		int n = 0;
		for (int j = 0; j < N; j++)
			if (input[j] % i == 0)n++;
		if (n == N)printf("%d\n", i);
	}
	return 0;
}