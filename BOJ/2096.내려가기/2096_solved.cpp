#include<stdio.h>
int min_(int a, int b) { return (a > b ? b : a); }
int max_(int a, int b) { return (a > b ? a : b); }
int main() {
	int N,i;
	int min[2][3], max[2][3];
	scanf("%d", &N);
	scanf("%d%d%d", &min[0][0], &min[0][1], &min[0][2]);
	for (i = 0; i < 3; i++)
		max[0][i] = min[0][i];
	for (i = 1; i < N; i++) {
		scanf("%d%d%d", &min[i % 2][0], &min[i % 2][1], &min[i % 2][2]);
		for (int j = 0; j < 3; j++)
			max[i % 2][j] = min[i % 2][j];
		min[i % 2][0] += min_(min[(i - 1) % 2][0], min[(i - 1) % 2][1]);
		min[i % 2][1] += min_(min[(i - 1) % 2][0], min_(min[(i - 1) % 2][1], min[(i - 1) % 2][2]));
		min[i % 2][2] += min_(min[(i - 1) % 2][2], min[(i - 1) % 2][1]);

		max[i % 2][0] += max_(max[(i - 1) % 2][0], max[(i - 1) % 2][1]);
		max[i % 2][1] += max_(max[(i - 1) % 2][0], max_(max[(i - 1) % 2][1], max[(i - 1) % 2][2]));
		max[i % 2][2] += max_(max[(i - 1) % 2][2], max[(i - 1) % 2][1]);
	}

	int M, m;
	M = 0, m = 1000000;
	for (int i = 0; i < 3; i++) {
		if (min[(N - 1) % 2][i] < m)
			m = min[(N - 1) % 2][i];
		if (max[(N - 1) % 2][i] > M)
			M = max[(N - 1) % 2][i];
	}

	printf("%d %d", M, m);
	return 0;

}