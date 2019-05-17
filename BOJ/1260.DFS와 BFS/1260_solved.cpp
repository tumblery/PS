#include<stdio.h>
#include<queue>
#include<stack>
#define MAX_N 1000
using namespace std;
int N, M, V;
bool adj[1001][1001];
bool visited[1001];

void init() {
	for (int i = 0; i <= MAX_N; i++)
		visited[i] = false;
}

void DFS() {
	stack<int> st;
	st.push(V);
	while (!st.empty()) {
		int now = st.top();
		if(!visited[now])printf("%d ", now);
		visited[now] = true;
		
		for (int i = 1; i <= N; i++) {
			if (visited[i])continue;
			if (adj[now][i]) {
				st.push(i);
				break;
			}
		}
		if (now == st.top())st.pop();
	}
	return;
}
void BFS() {
	queue<int> Q;
	Q.push(V);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		if (visited[now])continue;
		visited[now] = true;
		printf("%d ", now);
		for (int i = 0; i <= N; i++) {
			if (adj[now][i])Q.push(i);
		}
	}
	return;
}

int main() {
	int a, b;
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		adj[a][b] = true;
		adj[b][a] = true;
	}
	DFS();
	printf("\n");
	init();
	BFS();
	return 0;
}