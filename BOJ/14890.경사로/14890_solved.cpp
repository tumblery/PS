#include<stdio.h>
#define max_N 100

int map[max_N+1][max_N+1];
int N,L,ans;
int abs_(int a) {
	return a > 0 ? a : a*-1;
}
int main() {
	scanf("%d%d", &N,&L);
	int tmp;
	ans = 2*N;
	for (int i = 0; i < N; i++) {
		tmp = 0;
		bool is_road = true;
		bool flag = false;
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (is_road) {
				if (j == 0) {
					tmp = 1;
				}
				else {
					if (map[i][j - 1] == map[i][j]) {
						tmp++;
						if (flag && tmp >= L) {
							tmp -= L;
							flag = false;
						}
					}
					else {
						if (abs_(map[i][j - 1] - map[i][j]) == 1) {
							if (flag && tmp < L)is_road = false;
							else if (flag && tmp >= L)tmp -= L;
							if (map[i][j - 1] < map[i][j]) {
								if (tmp < L)is_road = false;
							}
							else {
								flag = true;
							}
							tmp = 1;
						}
						else {
							is_road = false;
						}
					}
				}
			}
		}
		if (flag && tmp < L)is_road = false;
		if (!is_road)ans--;
	}
	for (int i = 0; i < N; i++) {
		tmp = 0;
		bool is_road = true;
		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (is_road) {
				if (j == 0) {
					tmp = 1;
				}
				else {
					if (map[j-1][i] == map[j][i]) {
						tmp++;
						if (flag && tmp >= L) {
							tmp -= L;
							flag = false;
						}
					}
					else {
						if (abs_(map[j][i] - map[j-1][i]) == 1) {
							if (flag && tmp < L)is_road = false;
							else if (flag && tmp >= L)tmp -= L;
							if (map[j - 1][i] < map[j][i]) {
								if (tmp < L)is_road = false;
							}
							else {
								flag = true;
							}
							tmp = 1;
						}
						else {
							is_road = false;
						}
					}
				}
			}
		}
		if (flag && tmp < L)is_road = false;
		if (!is_road)ans--;
	}
	printf("%d", ans);
	return 0;
}


