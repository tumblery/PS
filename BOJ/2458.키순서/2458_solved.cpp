#include<stdio.h>
#include<vector>
#include<memory.h>

using namespace std;

vector<int> sadj[501],radj[501];
int svisited[501],rvisited[501],S[501],R[501];
void sDfs(int now, int cnt) {
	svisited[now] = cnt;
	for (int next : sadj[now]) {
		if (svisited[next] == cnt)continue;
		S[next]++;
		sDfs(next, cnt);
	}
}
void rDfs(int now, int cnt) {
	rvisited[now] = cnt;
	for (int next : radj[now]) {
		if (rvisited[next] == cnt)continue;
		R[next]++;
		rDfs(next, cnt);
	}
}
int main() {
	int N,M;
	scanf("%d%d", &N,&M);
	int u, v;
	for (int i = 1; i <= N; i++) {
		S[i] = 0;
		R[i] = 0;
		sadj[i].clear();
		radj[i].clear();
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		sadj[u].push_back(v); 
		radj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sDfs(i, i);
		rDfs(i, i);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (S[i] + R[i] == N - 1)ans++;
	}
	printf("%d", ans);
}
