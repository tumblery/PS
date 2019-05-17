#include<stdio.h>
int DVD[700000],loc[100000];
int MN, M;
void init_tree(int now) {
	if (DVD[now] != -1)return;
	init_tree(now * 2);
	init_tree(now*2+1);
	DVD[now] = DVD[now * 2] + DVD[now * 2 + 1];
}
void init(int N, int m) {
	MN = 1;
	while (1) {
		if (m + N <= MN)break;
		MN *= 2;
	}
	M = MN + m - 1;
	for (int i = 0; i < MN; i++) {
		DVD[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		DVD[i + MN] = 0;
	}
	for (int i = 0; i < N; i++) {
		DVD[i + MN+m] = 1;
	}
	for (int i = MN + N + m; i < MN * 2; i++)
		DVD[i] = 0;
	
	for (int i = 0; i < N; i++)
		loc[i] = m+i;
	init_tree(1);
	return;
}
int find_loc(int now,int st,int en,int l,int r) {
	if (st <= l && en >= r)return DVD[now];
	if (en <l || st > r)return 0;
	else return find_loc(now * 2, st, en, l, (l + r) / 2) + find_loc(now * 2 + 1, st, en, (l + r) / 2 + 1, r);
}
void update(int now,int diff) {
	int tmp = now;
	while (tmp >= 1) {
		DVD[tmp] += diff;
		tmp /= 2;
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		int n, m, dvd;
		scanf("%d%d", &n, &m);
		init(n, m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &dvd);
			dvd--;
			printf("%d ", find_loc(1, 0, loc[dvd], 0, MN-1)-1);
			update(loc[dvd] + MN, -1);
			loc[dvd] = m-i-1;
			update(loc[dvd] + MN, 1);
		}
		printf("\n");
	}
	return 0;
}