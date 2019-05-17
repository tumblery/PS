#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
#include<memory.h>
using namespace std;

int N, M, ans;
int map[8][8],test_map[8][8];
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
int max_(int a, int b) {
	return a > b ? a : b;
}
void check() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (test_map[i][j] == 0)tmp++;
		}
	}
	ans = max_(ans, tmp);
}
void BFS() {
	for (int i = 0; i < wall.size(); i++) {
		test_map[wall[i].first][wall[i].second] = 1;
	}
	bool visited[8][8] = { false, };
	for (int i = 0; i < virus.size(); i++) {
		queue<pair<int, int>> Q;
		Q.push({ virus[i].first,virus[i].second });
		while (!Q.empty()) {
			pair<int, int> now = Q.front();
			Q.pop();
			if (visited[now.first][now.second])continue;
			visited[now.first][now.second] = true;
			test_map[now.first][now.second] = 2;
			for (int i = 0; i < 4; i++) {
				int ni = now.first + dir[i][0];
				int nj = now.second + dir[i][1];
				if (ni < 0 || ni >= N || nj < 0 || nj >= M)continue;
				if (test_map[ni][nj] != 0)continue;
				Q.push({ ni,nj });
			}
		}
	}
	check();
}
void build_wall(int idx,int max) {
	if (wall.size() == max) {
		memcpy(test_map, map, sizeof(map));
		BFS();
		return;
	}
	if (idx >= M*N)return;
	
	build_wall(idx + 1, max);
	if (map[idx / M][idx%M] != 0)return;
	wall.push_back({ idx / M,idx%M });
	build_wall(idx + 1, max);
	wall.pop_back();
}

int main() {
	scanf("%d%d", &N, &M);
	wall.clear();
	virus.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)virus.push_back({ i,j });
		}
	}
	ans = 0;

	wall.clear();
	build_wall(0, 3);

	printf("%d", ans);
	return 0;
}