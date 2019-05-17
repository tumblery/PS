#include<stdio.h>

int main() {
	int ans, e, f, c, t;
	scanf("%d%d%d", &e, &f, &c);
	t = e + f;
	ans = 0;
	while (t >= c) {
		ans += t / c;
		e= t / c;
		t = t%c;
		t += e;
	}
	printf("%d", ans);
	return 0;
}