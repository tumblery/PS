#include<stdio.h>


int cnt[1000001] = { 0, };
int ans[1000001] = { 0, };
long long int sum[1000001] = { 0, };
int main() {
	int N, K, tmp,M;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		cnt[tmp]++;
	}
	ans[0] = sum[0] = K;
	for (int i = 1; i < N; i++) {
		if (cnt[i] > 0) {
			for (int j = i; j < N; j += i)
				ans[j] += cnt[i];
		}
	}
	for (int i = 0; i < N - 1; i++)
		sum[i + 1] = sum[i] + ans[i+1];
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int L,R;
		scanf("%d%d", &L, &R);
		printf("%lld\n", L == 0 ? sum[R] : sum[R] - sum[L - 1]);
	}
	return 0;
}