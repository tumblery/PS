#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;
const int INF = 987654321;
typedef struct Edge {
	int from, to;
	int dist;
};
//vector<pair<int, int>> adj[900];
vector<Edge> list;
int dist[900];
int map[31][31],T[31][31];
int dir[4][2] =
{
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};
void init(int W, int H) {
	list.clear();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			map[i][j] = i*W+j;
		//	adj[W*i + j].clear();
			dist[W*i + j] = INF;
			T[i][j] = 0;
		}
	}
}

int main() {
	int cnt = 1;
	while (1) {
		int W, H, G, E;
		scanf("%d%d", &W, &H);
		if (W == 0 && H == 0)break;
		init(W, H);
		scanf("%d", &G);
		for (int i = 0; i < G; i++) {
			int X, Y;
			scanf("%d%d", &X, &Y);
			map[Y][X] = -1;
		}
		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			int X1, X2, Y1, Y2,dist;
			scanf("%d%d%d%d%d", &X1, &Y1, &X2, &Y2,&dist);
			list.push_back({map[Y1][X1],map[Y2][X2],dist });
			T[Y1][X1] = -1;
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] < 0 || T[i][j] == -1)continue;
				for (int k = 0; k < 4; k++) {
					int I = dir[k][0] + i;
					int J = dir[k][1] + j;
					if ((I < 0) || (I >= H) || (J < 0) || (J >= W) || (map[I][J] == -1))continue;
					list.push_back({map[i][j],map[I][J],1 });
				}
			}
		}
		dist[0] = 0;
		int never_flag=0,update=1;
		for (int i = 0; i < H*W-G-1&&update==1; i++) {
			update = 0;
			for (auto L : list) {
				if (dist[L.from] == INF)continue;
				if (L.from == W*H - 1)continue;
				if (dist[L.to] > dist[L.from] + L.dist) {
					update = 1;
					dist[L.to] = dist[L.from] + L.dist;
				}
			}
		}
		for (auto L : list) {
			if (dist[L.from] == INF)continue;
			if (L.from == W*H - 1)continue;
			if(dist[L.to] >dist[L.from]+L.dist)
			{
				never_flag = 1; break;
			}
		}
		if (never_flag == 1)printf("Never\n");
		else if (dist[H*W - 1] == INF)printf("Impossible\n");
		else {
			printf("%d\n",dist[H*W - 1]);
		}
		cnt++;
	}
}