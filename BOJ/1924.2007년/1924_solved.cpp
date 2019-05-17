#include<stdio.h>

int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char* day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	int d = 0;
	if (x == 1) {
		d = y - 1;
	}
	else {
		for (int i = 1; i < x; i++) {
			d += month[i];
		}
		d += y;
		d--;
	}
	printf("%s", day[d % 7]);
	return 0;
}