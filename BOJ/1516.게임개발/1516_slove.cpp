#include<stdio.h>
#include<vector>
#include<queue>
typedef long long int ll;
using namespace std;
vector<int> adj[501];

ll ans[501],Time[501];
int visit[501],degree[501];
int N;

void init() {
	for (int i = 0; i <= N; i++) {
		adj[i].clear();
		ans[i] = 0;
		Time[i] = 0;
		visit[i] = 0;
		degree[i] = 0;
	}
}

int main() {
	scanf("%d", &N);
	init();
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &Time[i]);
		int from; 
		while (1) {
			scanf("%d", &from);
			if (from == -1)break;
			adj[from].push_back(i);
			degree[i]++;
		}
		if (degree[i] == 0)Q.push(i);
	}
	int idx = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		visit[idx++] = now;
		for (int next : adj[now]) {
			degree[next]--;
			if (degree[next] == 0)Q.push(next);
		}
	}
	for (int i = 0; i < N; i++) {
		int now = visit[i];
		ans[now] += Time[now];
		for (int next : adj[now]) {
			ans[next] = ans[now] < ans[next] ? ans[next] : ans[now];
		}
	}
	for (int i = 1; i <= N; i++)printf("%lld\n", ans[i]);
	return 0;
}

