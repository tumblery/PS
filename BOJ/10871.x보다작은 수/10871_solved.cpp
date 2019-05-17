#include<stdio.h>
int ans[10000];
int main() {
	int N, X, tmp,idx;
	idx = 0;
	scanf("%d%d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp < X) {
			ans[idx++] = tmp;
		}
	}
	for (int i = 0; i < idx; i++)
		printf("%d ", ans[i]);
}