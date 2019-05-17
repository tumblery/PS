#include<stdio.h>
#include<queue>
#define MAX_N 1000
using namespace std;
typedef long long int ll;
typedef struct info {
	ll my_time;
	int idx;
	int ch[MAX_N];
};
int N,W,K;
info list[MAX_N + 1];
ll times[MAX_N + 1];
int visited[MAX_N + 1];
int degree[MAX_N + 1];
ll max_(ll a, ll b) {
	return a > b ? a : b;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++)
			scanf("%lld", &list[i].my_time);
		for (int i = 0; i < K; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			list[a].ch[list[a].idx++] = b;
			degree[b]++;
		}
		queue<int> Q;
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0)Q.push(i);
		}
		scanf("%d", &W);
		int idx = 0;
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			visited[idx++] = now;
			for (int i = 0; i < list[now].idx; i++) {
				degree[list[now].ch[i]]--;
				if (degree[list[now].ch[i]] == 0)Q.push(list[now].ch[i]);
			}
		}
		for (int i = 0; i < N; i++) {
			int now = visited[i];
			times[now] += list[now].my_time;
			if (now == W)break;
			for (int j = 0; j < list[now].idx; j++)
				times[list[now].ch[j]] = max_(times[list[now].ch[j]], times[now]);
		}
		printf("%lld\n", times[W]);
		for (int i = 0; i <= N; i++) {
			list[i].idx = 0;
			degree[i] = 0;
			times[i] = 0;
		}
	}
	return 0;
}