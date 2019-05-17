#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> P;
bool visited[100][100] = { false, };
int map[100][100];
char input[101];
int N, M;
const int dir[4][2] = {
	{0,-1},
	{0,1},
	{1,0},
	{-1,0}
};
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		for (int j = 0; j < M; j++)
			map[i][j] = input[j] - '0';
	}
	int ans;
	queue<pair<int,P>> Q;
	Q.push({ 1,{ 0,0 } });
	while (!Q.empty()) {
		pair<int,P> now = Q.front();
		Q.pop();
		if (visited[now.second.first][now.second.second])continue;
		if (now.second.first == N - 1 && now.second.second == M - 1) {
			ans = now.first;
			break;
		}
		visited[now.second.first][now.second.second] = true;
		for (int i = 0; i < 4; i++) {
			int ni = now.second.first + dir[i][0];
			if (ni < 0 || ni >= N)continue;
			int nj = now.second.second + dir[i][1];
			if (nj < 0 || nj >= M)continue;
			if (map[ni][nj] == 0)continue;
			Q.push({ now.first + 1,{ni,nj} });
		}
	}
	printf("%d", ans);
	return 0;
}