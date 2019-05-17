#include<stdio.h>
#include<memory.h>
#define MAX 987654321
int N, W[16][16], dp[16][1 << 16];
int min(int a, int b) {
	return a < b ? a : b;
}
int tsp(int now, int visited) {
	int& ret = dp[now][visited];
	if (ret != -1)return ret;
	if(visited == (1 << N) - 1) {
		if (W[now][0] != 0)return W[now][0];
		return MAX;
	}
	ret = MAX;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i) || W[now][i] == 0)continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + W[now][i]);
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = tsp(0, 1);
	printf("%d", ans);
}