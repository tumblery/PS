#include<stdio.h>
#include<memory.h>
int ans,N, M;
bool visited[50][50];
int map[50][50];
char debugging[50][50];
int dir[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
int contray_dir[4] = { 2,3,0,1 };
void check() {
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (visited[i][j])ans++;
	}
	
}

void DFS(int x, int y,int ndir) {
	visited[x][y] = true;
	debugging[x][y] = 'O';
	int left_dir = ndir;
	for (int i = 0; i < 4; i++) {
		left_dir--;
		if (left_dir < 0)left_dir = 3;
		int ni = x + dir[left_dir][0];
		int nj = y + dir[left_dir][1];
		if (ni < 0 || nj < 0 || ni >= N || nj >= M)continue;
		if (visited[ni][nj]) continue;
		if (map[ni][nj] == 1)continue;
		return DFS(ni, nj, left_dir);
	}
	int ci = x + dir[contray_dir[ndir]][0];
	int cj = y + dir[contray_dir[ndir]][1];
	if (map[ci][cj] == 1 || ci < 0 || cj < 0 || ci >= N || cj >= M)
		return;
	return DFS(ci, cj, ndir);
}

int main() {
	int R, C, dir;
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &R, &C, &dir);
	memset(debugging, '-', sizeof(debugging));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)debugging[i][j] = 'X';
		}
	}

	DFS(R, C, dir);
	check();
	printf("%d", ans);
	return 0;
}