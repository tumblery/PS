#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<limits>
#include<functional>
#include<queue>
#include<math.h>
using namespace std;
const int Max = numeric_limits<int>::max();
int AMin, AMax;
vector<int> adj[100001], adjD[100001];
int dep[100001], dM[100001][18], dm[100001][18],par[100001][18];
int max_(int a, int b) {
	return (a > b ? a : b);
}
int min_(int a, int b) {
	return (a < b ? a : b);
}
void init(int N) {
	for (int i = 0; i <= N; i++) {
		adj[i].clear();
		adjD[i].clear();
		dep[i] = -1;
		for (int j = 0; j < 18; j++) {
			dm[i][j] = Max;
			dM[i][j] = 0;
			par[i][j] = 0;
		}
	}
}
void BFS(int root) {
	queue<int> Q;
	Q.push(root);
	dep[root] = 0;
	par[root][0] = root;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			int dist = adjD[now][i];
			if (dep[next] == -1) {
				dep[next] = dep[now] + 1;
				par[next][0] = now;
				dM[next][0] = dist;
				dm[next][0] = dist;
				Q.push(next);
			}
		}
	}
}
void get_lca(int N) {
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			dM[j][i] = max_(dM[j][i - 1], dM[par[j][i - 1]][i - 1]);
			dm[j][i] = min_(dm[j][i - 1], dm[par[j][i - 1]][i - 1]);
		}
	}
}

void find(int a, int b) {
	if (dep[a] < dep[b]) {
		return find(b, a);
	}
	for (int i = 17; i >= 0; i--) {
		while (a != b&&dep[par[a][i]] >= dep[b]) {
			AMin = min_(AMin, dm[a][i]);
			AMax = max_(AMax, dM[a][i]);
			a = par[a][i];
		}
	}
	for (int i = 17; i >= 0; i--) {
		while (a != b&& par[a][i] != par[b][i]) {
			AMin = min_(AMin, min_(dm[a][i],dm[b][i]));
			AMax = max_(AMax, max_(dM[a][i],dM[b][i]));
			a = par[a][i];
			b = par[b][i];
		}
	}
	if (a != b) {
		AMin = min_(AMin, min_(dm[a][0], dm[b][0]));
		AMax = max_(AMax, max_(dM[a][0], dM[b][0]));
	}
}
int main() {
	int N, K;
	scanf("%d", &N);
	init(N);
	for (int i = 1; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(b);
		adj[b].push_back(a);
		adjD[a].push_back(c);
		adjD[b].push_back(c);
	}
	BFS(1);
	get_lca(N);
	scanf("%d", &K);
	//int cnt = 1;
	while (K--) {
		int a, b;
		scanf("%d %d", &a, &b);
		AMin = Max;
		AMax = 0;
		find(a, b);
		printf("%d %d\n",AMin, AMax);
	}
} 