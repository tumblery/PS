#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

typedef struct pos {
	int x, y;
};
typedef struct dist {
	int chicken, home;
	int d;
	bool operator <(const dist& a)const {
		return d > a.d;
	}
};
int ans,chick_N;
vector<pos> chicken, home;
int _abs(int a) {
	return a < 0 ? a*-1 : a;
}
int _min(int a, int b) {
	return a < b ? a : b;
}
void calc_dist(vector<pos> chick) {
	bool visited[101] = { false, };
	priority_queue<dist> D;
	for (int i = 0; i < chick.size(); i++) {
		for (int j = 0; j < home.size(); j++) {
			D.push({ i,j,(_abs(chick[i].x - home[j].x) + _abs(chick[i].y - home[j].y)) });
		}
	}
	int ret = 0, cnt = 0;
	while (!D.empty()) {
		dist now = D.top();
		D.pop();
		if (visited[now.home])continue;
		visited[now.home] = true;
		ret += now.d;
		cnt++;
		if (cnt == home.size())break;
	}
	ans = _min(ans, ret);
}
void select(vector<pos> chick, int idx,int M) {
	if (chick.size() == M) {
		calc_dist(chick);
		return;
	}
	if (idx >= chick_N)return;
	select(chick, idx + 1, M);
	chick.push_back(chicken[idx]);
	select(chick, idx + 1, M);
	chick.pop_back();
}

int main() {
	int N,M,tmp;
	scanf("%d%d", &N,&M);
	chick_N = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (tmp == 1) {
				home.push_back({ i,j });
			}
			else if (tmp == 2) {
				chicken.push_back({ i,j });
				chick_N++;
			}
		}
	}
	vector<pos> t;
	ans = 100000;
	select(t, 0, M);
	printf("%d", ans);
	return 0;
}