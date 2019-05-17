#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int dir[8][2] = {
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1}
};
pair<int, int> Post;
int N,Knum;
char map[51][51];
int H[51][51],Hlist[51*51];
int deliver(int lo, int hi) {
	if (H[Post.first][Post.second] < lo || H[Post.first][Post.second] > hi)return 0;
	int visit[51][51] = { 0, };
	queue<pair<int, int>> list;
	pair<int, int> tmp;
	int ret = 0;
	list.push(Post);
	visit[Post.first][Post.second] = 1;
	while (!list.empty()) {
		pair<int, int> now = list.front();
		list.pop();
		for (int i = 0; i < 8; i++) {
			tmp.first = now.first + dir[i][0];
			tmp.second = now.second + dir[i][1];
			if (tmp.first < 0 || tmp.first >= N)continue;
			if (tmp.second < 0 || tmp.second >= N)continue;
			if (visit[tmp.first][tmp.second] == 1)continue;
			if (H[tmp.first][tmp.second] < lo || H[tmp.first][tmp.second] >hi) {
				if (map[tmp.first][tmp.second] == 'K')return 0;
				continue;
			}
			visit[tmp.first][tmp.second] = 1;
			list.push(tmp);
			if (map[tmp.first][tmp.second] == 'K')ret++;
		}
	}
	return ret;
}
int main() {

	scanf("%d\n", &N);
	Knum = 0;
	for (int i = 0; i < N; i++) {
			scanf("%s", &map[i]);
			for(int j=0;j<N;j++){
				if (map[i][j] == 'P') {
					Post.first = i;
					Post.second = j;
			}
				else if (map[i][j] == 'K') {
					Knum++;
			}
		}
	}
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &H[i][j]);
			Hlist[idx++] = H[i][j];
		}
	}
	sort(Hlist, Hlist + idx);
	int HList[51 * 51];
	int idx_h = 0;
	HList[idx_h++] = Hlist[0];
	for (int i = 1; i < idx; i++) {
		if (HList[idx_h - 1] == Hlist[i])continue;
		HList[idx_h++] = Hlist[i];
	}
	int ans = 1000001;
	for (int i = 0; i < idx_h; i++) {
		int st, en, mid;
		st = i;
		en = idx_h - 1;
		while (st <= en) {
			mid = (st+en)/2;
			if (deliver(HList[i], HList[mid]) == Knum) {
				if (ans > HList[mid] - HList[i])ans = HList[mid] - HList[i];
				en = mid-1;
			}
			else {
				st = mid+1;
			}
		}
	}
	printf("%d", ans);
}