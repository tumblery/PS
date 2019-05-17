#include<stdio.h>
#include<memory.h>
const int M_N = 10001;
int N, W;
int memo[M_N][4][4];
int map[M_N][2];
//0 ,1 안쪽 사용 2:바깥쪽 사용 3 세로모양
int min_(int a, int b) {
	return a < b ? a : b;
}
int gong(int idx, int prev, int last) {
	int& ret = memo[idx][prev][last];
	if (ret!= -1)return ret;
	bool in, out, one;
	in = ((map[idx][0] + map[idx == 0 ? N - 1 : idx - 1][0]) <= W);
	out = ((map[idx][1] + map[idx == 0 ? N - 1 : idx - 1][1]) <= W);
	one = ((map[idx][0] + map[idx][1]) <= W);
	if (idx == N - 1) {
		if (idx == 0)return one ? 1 : 2;
		ret = 2;
		if (last == 0) {
			if (in && !(prev & 1))ret = 1;
			if (out&& prev < 2)ret = 1;
			if (one)ret = 1;
			if (in && out && prev == 0)ret = 0;
		}
		else if (last == 1) {
			if (out && prev < 2)ret = 1;
		}
		else if (last == 2) {
			if (in && !(prev & 1))ret = 1;
		}
		return ret;
	}
	ret = 2 + gong(idx + 1, 0, idx == 0 ? 0 : last);
	if (in && !(prev & 1))
		ret = min_(ret, 1 + gong(idx + 1, 1, idx == 0 ? 1 : last));
	if (out && prev < 2)
		ret = min_(ret, 1 + gong(idx + 1, 2, idx == 0 ? 2 : last));
	if (one)
		ret = min_(ret, 1 + gong(idx + 1, 3, idx == 0 ? 0 : last));
	if (in && out && prev == 0)
		ret = min_(ret, gong(idx + 1, 3, idx == 0 ? 3 : last));
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		memset(memo, -1, sizeof(memo));
		scanf("%d%d", &N, &W);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[j][i]);
			}
		}
		printf("%d\n", gong(0, 0, 0));
	}
	return 0;
}