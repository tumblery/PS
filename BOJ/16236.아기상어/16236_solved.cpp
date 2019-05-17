#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct pos {
	int x, y;
	bool operator<(const pos& a)const {
		return x == a.x ? y < a.y : x < a.x;
	}
};
typedef struct node {
	int dep;
	int x, y;
};
int map[21][21],N;
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

int bfs(int size, int& x, int& y) {
	bool visited[21][21] = { false, };
	vector<pos> ans_candi;
	queue<node> Q;
	int prev = 0,ret = -1;
	Q.push({ 0,x,y });
	while (!Q.empty()) {
		node  now = Q.front();
		Q.pop();
		if (visited[now.x][now.y])continue;
		if (ans_candi.empty() && prev != now.dep) {
			prev = now.dep;
		}
		if (!ans_candi.empty() && prev != now.dep) {
			ret = prev+1;
			break;
		}
		visited[now.x][now.y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dir[i][0];
			int ny = now.y + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (map[nx][ny] <= size) {
				Q.push({ now.dep + 1,nx,ny });
				if (map[nx][ny] < size && map[nx][ny] >0) {
					ans_candi.push_back({ nx,ny });
				}
			}
		}
	}
	if (ans_candi.size() > 0) {
		sort(ans_candi.begin(), ans_candi.end());
		x = ans_candi[0].x;
		y = ans_candi[0].y;
	}
	return ret;
}
int trevel(int x,int y) {
	int size = 2;
	int cnt = 0;
	int ret = 0;int time;
	while ((time = bfs(size,x,y)) > -1) {
		cnt++;
		map[x][y] = 0;
		if (cnt >= size) {
			size++;
			cnt = 0;
		}
		ret += time;
	}
	return ret;
}
int main() {
	int x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				x = i; y = j;
				map[i][j] = 0;
			}
		}
	}
	printf("%d",trevel(x, y));
}