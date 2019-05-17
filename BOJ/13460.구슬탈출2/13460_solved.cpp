#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;
typedef struct node {
	pair<int, int> R, B;
	int cnt;
};
int N, M;
int board[11][11];
bool visited[11][11][11][11] = { false, };
//0 지나감 1 장애물 2 목표
pair<int, int> red, blue,goal;
int dir_i[4] = { 0,0,-1,1 };
int dir_j[4] = { 1,-1,0, 0 };

int main() {
	char tmp;
	scanf("%d%d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &tmp);
			if (tmp == '.')board[i][j] = 0;
			else if (tmp == '#')board[i][j] = 1;
			else if (tmp == 'R') {
				board[i][j] = 0;
				red = { i,j };
			}
			else if (tmp == 'B') {
				board[i][j] = 0;
				blue = { i,j };
			}
			else if(tmp == 'O'){
				goal = { i,j };
				board[i][j] = 2;
			}
		}
		getchar();
	}
	queue<node> S;
	S.push({ red,blue,0 });
	visited[red.first][red.second][blue.first][blue.second] = true;
	int ans = -1;
	while (!S.empty()) {
		node now = S.front();
		S.pop();
		if (now.cnt > 10)break;
		if (now.R == goal) {
			ans = now.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			pair<int, int>nr, nb;
			int rc, bc;
			nr = now.R;
			nb = now.B;
			rc = bc = 0;
			while (board[nr.first][nr.second] == 0) {
				nr.first += dir_i[i];
				nr.second += dir_j[i];
				rc++;
			}
			if (board[nr.first][nr.second] == 1) {
				nr.first -= dir_i[i];
				nr.second -= dir_j[i];
				rc--;
			}
			while (board[nb.first][nb.second] == 0) {
				nb.first += dir_i[i];
				nb.second += dir_j[i];
				bc++;
			}
			if (board[nb.first][nb.second] == 1) {
				nb.first -= dir_i[i];
				nb.second -= dir_j[i];
				bc--;
			}
			if (nb == goal)continue;
			if (nr == nb) {
				rc > bc ? nr.first -= dir_i[i] : nb.first -= dir_i[i];
				rc > bc ? nr.second -= dir_j[i] : nb.second -= dir_j[i];
			}
			if (visited[nr.first][nr.second][nb.first][nb.second])continue;
			S.push({ nr,nb,now.cnt + 1 });
			visited[nr.first][nr.second][nb.first][nb.second] = true;
		}
	}
	printf("%d", ans);
}