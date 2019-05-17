#include<stdio.h>

int dp[2][1001][1001];
int card[1001];
int N;
int min_(int a, int b) {
	return a < b ? a : b;
}
int max_(int a, int b) {
	return b > a ? b : a;
}
int solve(int st, int en, int turn) {
	if (dp[turn % 2][st][en] != -1)return dp[turn % 2][st][en];
	if (st == en) {
		if (turn % 2 == 0)
			return card[st];
		else return 0;
	}
	int ret = 0;
	if (turn % 2 == 0) {
		dp[turn % 2][st][en] = max_(card[st] + solve(st + 1, en, (turn + 1) % 2),solve(st, en - 1, (turn + 1) % 2) + card[en]);
	}
	else {
		dp[turn % 2][st][en] = min_(solve(st + 1, en, (turn + 1) % 2), solve(st, en - 1, (turn + 1) % 2));
	}
	return dp[turn % 2][st][en];
}
void init() {
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &card[i]);
		init();
		int ans = solve(1, N, 0);
		printf("%d\n", ans);
	}
}