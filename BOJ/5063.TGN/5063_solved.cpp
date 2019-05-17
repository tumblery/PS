#include<stdio.h>

int main() {
	int N, a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a < b - c) {
			printf("advertise\n");
		}
		else if (a == b - c) {
			printf("does not matter\n");
		}
		else {
			printf("do not advertise\n");
		}
	}
	return 0;
}