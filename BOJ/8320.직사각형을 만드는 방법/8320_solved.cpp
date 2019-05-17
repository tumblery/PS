#include<stdio.h>

int main() {
	int N, ans, i, j;
	scanf("%d", &N);
	ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = i; j <= N; j++) {
			if (i*j <= N)ans++;
			else {
				break;
			}
		}
		if (i == j)break;
	}
	printf("%d", ans);
	return 0;
}