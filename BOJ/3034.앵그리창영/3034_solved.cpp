#include<stdio.h>

int main() {
	int N, W, H,M,f;
	scanf("%d%d%d", &N, &W, &H);
	M = W*W + H*H;
	for (int i = 0; i < N; i++) {
		scanf("%d", &f);
		if (f*f <= M)printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}