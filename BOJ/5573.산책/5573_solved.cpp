#include<stdio.h>
int dir[2][2] = {
	{1,0},
	{0,1}
};
int map[1002][1002],cnt[1002][1002];
int H, W, N;
int ans[2];
int main() {
	scanf("%d%d%d", &H, &W, &N);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
			cnt[i][j] = 0;
		}
	}
	cnt[1][1] = N-1;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (cnt[i][j] == 0)continue;
			cnt[i + 1][j] += cnt[i][j] / 2;
			cnt[i][j + 1] += cnt[i][j] / 2;
			if (cnt[i][j] % 2 == 1) {
				if (map[i][j] == 1)cnt[i][j + 1]++;
				else cnt[i + 1][j]++;
				map[i][j] = (map[i][j] == 0 ? 1 : 0);
			}
		}
	}
	int I =1,J = 1;
	while (I <= H&&J <= W) {
		if (map[I][J] == 0)I++;
		else J++;
	}
	printf("%d %d",I, J);
	return 0;
}