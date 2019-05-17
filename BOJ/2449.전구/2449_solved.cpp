#include<stdio.h>

int dp[201][201];
int input[201];
int N,K;
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	scanf("%d%d", &N,&K);
	for (int i = 1; i <= N; i++)
		dp[i][i] = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &input[i]);
		for (int j = i; j >= 1; j--) {
			if (i == j) {
				continue;
			}
			dp[j][i] = 987654321;
			for (int k = j; k <= i; k++) {
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + (input[j] != input[k + 1]));
			}
		}
	}
	printf("%d", dp[1][N]);
	return 0;
}