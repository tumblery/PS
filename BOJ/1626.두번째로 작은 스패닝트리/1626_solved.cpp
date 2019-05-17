#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>
using namespace std;
typedef struct list {
	int from, to;
	int dist;
	bool operator <(const list& A)const {
		return dist < A.dist;
	}
};
const int MAX = (1ll << 31) - 1;
vector<int> adj[50001], adjv[50001];
vector<list> L;
int edges[200001];
int parent[50001],dep[50001],lca[50001][17],Dmax[50001][17],Dsmax[50001][17];
int find_par(int x) {
	if (parent[x] == x)return x;
	parent[x] = find_par(parent[x]);
	return parent[x];
}
void union_(int a, int b) {
	int A = find_par(a);
	int B = find_par(b);
	parent[A] = B;
}
void init(int N) {
	L.clear();
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		dep[i] = -1;
		adj[i].clear();
		adjv[i].clear();
		for (int j = 0; j < 17; j++) {
			lca[i][j] = 0;
			Dmax[i][j] = Dsmax[i][j] = -1;
		}
	}
}
int main() {
	int E,V;
	scanf("%d%d", &V,&E);
	init(V);
	for (int i = 0; i < E; i++) {
		int from, to, dist;
		scanf("%d%d%d", &from, &to, &dist);
		L.push_back({ from,to,dist });
		
	}
	sort(L.begin(), L.end());
	int edge = 0, ans = 0;
	vector<list> candi;
	for (int idx = 0; idx < E;idx++) {
		int A = L[idx].from;
		int B = L[idx].to;
		if ( edge <(V-1) && find_par(A) != find_par(B))
			{
			union_(A, B);
			ans += L[idx].dist;
			adj[L[idx].from].push_back(L[idx].to);
			adj[L[idx].to].push_back(L[idx].from);
			adjv[L[idx].from].push_back(L[idx].dist);
			adjv[L[idx].to].push_back(L[idx].dist);
			edge++;
		}
		else {
			candi.push_back(L[idx]);
		}	
	}
	if (edge != V - 1) {
		printf("-1");
		return 0;
	}
	queue<int> Q;
	Q.push(1);
	dep[1] = 0;
	lca[1][0] = 1;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			int dist = adjv[now][i];
			if (dep[next] == -1) {
				dep[next] = dep[now] + 1;
				lca[next][0] = now;
				Dmax[next][0] = dist;
				Dsmax[next][0] = -1;
				Q.push(next);
			}
		}
	}

	int len[4];
	for (int line = 1; line < 17; line++) {
		for (int i = 1; i <= V; i++) {
			lca[i][line] = lca[lca[i][line-1]][line-1];
			len[0] = Dmax[i][line - 1];
			len[1] = Dmax[lca[i][line - 1]][line - 1];
			len[2] = Dsmax[i][line - 1];
			len[3] = Dsmax[lca[i][line - 1]][line - 1];
			for (int k = 0; k < 4; k++)
				Dmax[i][line] = (Dmax[i][line] > len[k] ? Dmax[i][line] : len[k]);
			for (int k = 0; k < 4; k++)
				if (Dmax[i][line] > len[k])
					Dsmax[i][line] = (Dsmax[i][line] > len[k] ? Dsmax[i][line] : len[k]);
		}
	}
	int diff = MAX;
	for (int i = 0; i < candi.size(); i++) {
		int A, B,Diff;
		A = dep[candi[i].from] > dep[candi[i].to] ? candi[i].from : candi[i].to;
		B = dep[candi[i].from] <= dep[candi[i].to] ? candi[i].from : candi[i].to;
		Diff = dep[A] - dep[B];
		int idx = 0;
		for (int j = 0; j <17 && Diff > 0; j++) {
			if (Diff % 2 == 1) {
				edges[idx++] = Dmax[A][j];
				edges[idx++] = Dsmax[A][j];
				A = lca[A][j];
			}
			Diff /= 2;
		}

		for (int j = 16; j >= 0 && A != B; j--) {
			if (lca[A][j] != lca[B][j]) {
				edges[idx++] = Dmax[A][j];
				edges[idx++] = Dsmax[A][j];
				edges[idx++] = Dmax[B][j];
				edges[idx++] = Dsmax[B][j];
				A = lca[A][j];
				B = lca[B][j];
			}
		}
		if (A != B) {
			edges[idx++] = Dmax[A][0];
			edges[idx++] = Dmax[B][0];
		}
		int M = -1;
		for (int j = 0; j < idx; j++) {
			if (edges[j] > -1 && edges[j] < candi[i].dist && M < edges[j])M = edges[j];
		}
		if (M > -1 && diff > candi[i].dist - M)diff = candi[i].dist - M;
	}
	if (diff == MAX)printf("-1");
	else printf("%d", ans + diff);
}