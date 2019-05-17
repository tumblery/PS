#include<stdio.h>

using namespace std;
int prime_candi[1000000], prime[100000], pidx;
int num[100][100000],A[100000];

void init() {
	pidx = 0;
	for (int i = 0; i < 1000000; i++)
		prime_candi[i] = 0;
	for (int i = 2; i < 1000000; i++) {
		if (prime_candi[i] == 0) {
			prime_candi[i] = 1;
			prime[pidx++] = i;
			for (int j = i * 2; j < 1000000; j += i) {
				prime_candi[j] = -1;
			}
		}
	}
}
void init(int N) {
	for (int i = 0; i < pidx; i++) {
		A[i] = 0;
		for (int j = 0; j < N; j++) {
			num[j][i] = 0;
		}
	}
}
int main() {
	int N;
	init();
	scanf("%d", &N);
	init(N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int j = 0; j < pidx; j++) {
			while (tmp % prime[j] == 0) {
				num[i][j]++;
				A[j]++;
				tmp /= prime[j];
			}
			if (tmp == 0)break;
		}
	}
	long long int ans = 1;
	int ans_cnt = 0;
	for (int i = 0; i < pidx; i++) {
		int cnt = A[i] / N;
		for (int j = 0; j < N; j++) {
			if (cnt - num[j][i] > 0)
				ans_cnt += (cnt - num[j][i]);
		}
		for (int j = 0; j < cnt; j++)
			ans *= (long long int)prime[i];
	}
	printf("%lld %d", ans, ans_cnt);
}