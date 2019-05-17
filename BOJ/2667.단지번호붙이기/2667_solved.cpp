#include<stdio.h>
#include<algorithm>
using namespace std;
#define max_N 25
int group[max_N][max_N] = { 0, };
int map[max_N][max_N] = { 0, };
int ans[max_N*max_N];
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
int apt,cnt,N;

void dfs(int I, int J) {
	if (map[I][J] == 0)return;
	if (group[I][J] != 0)return;
	group[I][J] = apt;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ni = dir[i][0]+I;
		int nj = dir[i][1] + J;
		if (ni < 0 || ni >= N || nj < 0 || nj >= N)continue;
		dfs(ni, nj);
	}
}

int main() {
	scanf("%d", &N);
	char input[25] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		for (int j = 0; j < N; j++)
			map[i][j] = input[j] - '0';
	}
	cnt = 0;
	apt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				dfs(i, j);
				ans[apt] = cnt;
				cnt = 0;
				apt++;
			}
		}
	}
	sort(ans + 1, ans + apt);
	printf("%d\n", apt - 1);
	for (int i = 1; i < apt; i++)
		printf("%d\n", ans[i]);
	return 0;
}