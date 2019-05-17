#include<stdio.h>
int main() {
	int N, M, K, cnt;
	cnt = 1;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		int nextM = M % (N - i + 1) == 0 ? N - i + 1 : M % (N - i + 1);
		if (K == nextM || i == N) {
			cnt = i;
			break;
		}
		else {
			K = K > nextM ? K - nextM : N - i + 1 + K - nextM;
		}
	}
	printf("%d", cnt);
	return 0;
}