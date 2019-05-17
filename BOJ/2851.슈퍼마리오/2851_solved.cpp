#include<stdio.h>
#define standard 100
int abs_(int a) {
	return a > 0 ? a : a*-1;
}

int main() {
	int tmp, total,flag;
	total = flag = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		if (!flag) {
			int prev = abs_(standard - total);
			int now = abs_(standard - total - tmp);
			if ( prev >= now) {
				total += tmp;
			}
			else {
				flag = 1;
			}
		}
	}
	printf("%d", total);
	return 0;
}