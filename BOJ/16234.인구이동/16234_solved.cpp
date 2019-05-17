#include<stdio.h>
#include<vector>
#include<memory.h>
#define MAX_N 50
using namespace std;

typedef struct grouping {
	int people;
	int cnt;
	int res;
};

int map[MAX_N][MAX_N], parent[MAX_N*MAX_N];
int N, L, R;
int dir[2][2] = {
	{0,1},
	{1,0}
};
int abs_(int a) {
	return a > 0 ? a : a*-1;
}
void init_par() {
	for (int i = 0; i < N*N; i++)
		parent[i] = i;
}
int find_par(int a) {
	if (parent[a] == a)return a;
	parent[a] = find_par(parent[a]);
	return parent[a];
}
void union_(int a, int b) {
	int A = find_par(a);
	int B = find_par(b);
	parent[A] = B;
}
int solve() {
	int ans = 0;
	int g = 1;
	int flag = true;;
	while (1) {
		flag = true;
		init_par();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 2; k++) {
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx < 0 || nx >= N)continue;
					if (ny < 0 || ny >= N)continue;
					int diff = abs_(map[i][j] - map[nx][ny]);
					if (diff >= L && diff <= R) {
						flag = false;
						int a = i*N + j;
						int b = nx*N + ny;
						if (find_par(a) != find_par(b)) {
							union_(a, b);
						}
					}
				}
			}
		}
		if (flag)break;
		ans++;
		grouping U[MAX_N*MAX_N] = { 0, };
		for (int i = 0; i < N*N; i++) {
			int par = find_par(i);
			U[par].cnt++;
			U[par].people += map[i / N][i%N];
		}
		for (int i = 0; i < N*N; i++) {
			int par = find_par(i);
			if(par == i)
				U[par].res = U[par].people / U[par].cnt;
			
		}
		for (int i = 0; i < N*N; i++) {
			int par = find_par(i);
			map[i / N][i%N] = U[par].res;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d",solve());
}