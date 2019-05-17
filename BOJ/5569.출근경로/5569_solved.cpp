#include<stdio.h>
#define MOD 100000
int map[4][101][101];
int tmp[101][101];
int main() {
	int W, H;
	scanf("%d%d", &W, &H);
	for (int i = 2; i <= W; i++)map[0][1][i] = 1;
	for (int i = 2; i <= H; i++)map[2][i][1] = 1;
	for (int i = 2; i <= H; i++) {
		for (int j = 2; j <= W; j++) {
			map[0][i][j] = (map[0][i][j - 1] + map[1][i][j - 1]) % MOD;
			map[1][i][j] = map[2][i][j - 1];
			map[2][i][j] = (map[2][i - 1][j] + map[3][i - 1][j]) % MOD;
			map[3][i][j] = map[0][i - 1][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++)
		ans += (map[i][H][W] % MOD);
	printf("%d", ans%MOD);
	return 0;
}