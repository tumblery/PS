#include<stdio.h>

int N, M,ans;
int list[101];
int max_(int a, int b) {
	return a > b ? a : b;
}
void solve(int  sum, int sidx, int idx) {
	if (sidx >= 3) {
		if (sum <= M)
			ans = max_(ans, sum);
		return;
	}
	if (idx >= N)return;
	solve(sum, sidx, idx + 1);
	solve(sum + list[idx], sidx + 1, idx + 1);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &list[i]);
	ans = 0;
	solve(0, 0, 0);
	printf("%d", ans);
	return 0;
}