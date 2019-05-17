#include<stdio.h>

int A[1000000], N, B, C;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d%d", &B, &C);
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ans++;
		if (A[i] > 0) {
			ans += A[i] / C;
			if (A[i] % C > 0) ans++;
		}
	}
	printf("%lld", ans);
	return 0;
}