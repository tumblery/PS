#include<stdio.h>
#include<memory.h>
#include<utility>
#include<vector>
using namespace std;
pair<int, int> dir_list[100];
int map[101][101];
int logs[101][101];
int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int main() {
	memset(logs, 0, sizeof(logs));
	memset(map, 0, sizeof(map));
	int N, K, L, x, y;
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &x, &y);
		map[x][y] = 2;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		char tmp;
		scanf("%d %c", &dir_list[i].first, &tmp);
		if (tmp == 'D')dir_list[i].second = 1;
		else dir_list[i].second = -1;
	}
	int ans = 0,Lidx =0,hnd = 0,len=1;
	pair<int, int> head;
	head.first = 1;
	head.second = 1;


	while (1) {
			
		if (head.first <= 0 || head.first > N || head.second <= 0 || head.second >N)break;
		
		if (map[head.first][head.second] == 2) {
			logs[head.first][head.second] = ans;
			map[head.first][head.second] = 0;
			len++;
		}
		else if (ans >0 && logs[head.first][head.second] >0 && ans - logs[head.first][head.second] <= len) {
			break;
		}
		else {
			logs[head.first][head.second] = ans;
		}
		
		if (Lidx < L) {
			if (ans == dir_list[Lidx].first) {
				hnd += 4 + dir_list[Lidx].second;
				hnd %= 4;
				Lidx++;
			}
		}
		head.first += dir[hnd][0];
		head.second += dir[hnd][1];

		ans++;	
	}
	printf("%d", ans);
	return 0;
}