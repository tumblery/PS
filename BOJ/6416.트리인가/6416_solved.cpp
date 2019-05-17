#include<stdio.h>
#include<memory.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int parents[100001];
int visit[100001];
map<int,int> nodes;//key: node value : node_index
vector<int> adj[100001];

int main() {
	int u, v;
	int Case = 1;

	while (1) {
		int is_Tree = 1;
		int idx = 0;	
		memset(parents, 0, sizeof(parents));
		nodes.clear();
		while (1) {
			scanf("%d%d", &u, &v);
			if (u < 0 && v < 0)break;
			if (u == 0 && v == 0)break;
			if (nodes.find(u) == nodes.end()) {
				parents[idx] = 0;
				adj[idx].clear();
				nodes[u] = idx++;

			}
			if (nodes.find(v) == nodes.end()) {
				parents[idx] = 1;
				adj[idx].clear();
				nodes[v] = idx++;
			}
			else {
				parents[nodes[v]]++;
			}
			adj[nodes[u]].push_back(nodes[v]);
		}
		if (u < 0 && v < 0)break;
		queue<int> Q;
		for (int i = 0; i < idx; i++) {
			visit[i] = 0;
			if (parents[i] == 0) {
				Q.push(i);
				visit[i] = 1;
			}
		}
		if (idx > 0&&Q.size() != 1) {
			printf("Case %d is not a tree.\n", Case++);
			continue;
		}
		//BFS�� Ʈ�� Ž��
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			for (int next : adj[now]) {
				if (visit[next] == 0) {
					visit[next] = 1;
					Q.push(next);
				}
				//���� �湮�ߴ� ���� �ٽ� �������Ѵٸ�Ʈ���� �ɼ� ����.
				else {
					is_Tree = 0;
				}
			}
		}
		//���� BFS�� Ž������ ���� ���� �����Ѵٸ� �װ��� Ʈ���� �ƴϴ�.
		for (int i = 0; i < idx; i++) {
			if (visit[i] == 0)is_Tree = 0;
		}
		if (is_Tree == 1)printf("Case %d is a tree.\n", Case++);
		else printf("Case %d is not a tree.\n", Case++);
	}
}
