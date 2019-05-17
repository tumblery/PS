#include<stdio.h>

int index[501] = { 0, };
int adj[501][501] = { 0, };
int invite[501] = { 0, };

int main() {
	int N, M, a, b;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		adj[a][index[a]++] = b;
		adj[b][index[b]++] = a;
	}
	for (int i = 0; i < index[1]; i++) {
		int MyF = adj[1][i];
		invite[MyF] = 1;
		for (int j = 0; j < index[MyF]; j++) {
			invite[adj[MyF][j]] = 1;
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; i++)
		if (invite[i])ans++;
	printf("%d", ans);
	return 0;
}