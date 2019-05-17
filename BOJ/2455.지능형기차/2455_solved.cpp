#include<stdio.h>

int on[4], off[4];
int Max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int max =0,people = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &off[i], &on[i]);
		people -= off[i];
		max = Max(max, people);
		people += on[i];
		max = Max(max, people);
	}

	printf("%d", max);
	return 0;
}