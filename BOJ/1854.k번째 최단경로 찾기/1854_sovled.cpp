#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
const int INF = 1000 * 1000 + 1;
int N, M, K;
vector<int> adj[1001], adjv[1001];
int Dist[10001][100],index[1001];//[N][k];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i <= N; i++) {
		adj[i].clear();
		adjv[i].clear();
		index[i] = 0;
		for (int j = 0; j < 100; j++) {
			Dist[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B, dist;
		scanf("%d%d%d", &A, &B, &dist);
		adj[A].push_back(B);
		adjv[A].push_back(dist);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	PQ.push({ 0,1 });
	Dist[1][index[1]++] = 0;
	while (!PQ.empty()) {
		pair<int, int> now = PQ.top();
		PQ.pop();
		for (int i = 0; i < adj[now.second].size(); i++) {
			int next = adj[now.second][i];
			int dist = adjv[now.second][i] + now.first;
			int I;
			if (index[next] < K) {
				I = index[next]++;
				Dist[next][I] = dist;
				PQ.push({ dist,next });
			}
			else if (Dist[next][K - 1] > dist) {
				Dist[next][K - 1] = dist;
				I = K - 1;
				PQ.push({ dist,next });
			}
			else continue;
			sort(Dist[next], Dist[next] + I+1);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (Dist[i][K - 1] == INF)printf("-1\n");
		else printf("%d\n", Dist[i][K - 1]);
		
	}return 0;
}