#include<stdio.h>
int mul[4] = { 1,5,2,2 };
int calc_ab(int Me[4], int device[4]) {
	int total[4];
	total[0] = (Me[0] + device[0]) < 1 ? 1 : (Me[0] + device[0]);
	total[1] = (Me[1] + device[1]) < 1 ? 1 : (Me[1] + device[1]);
	total[2] = (Me[2] + device[2]) < 0 ? 0 : (Me[2] + device[2]);
	total[3] = Me[3] + device[3];
	int ret = 0;
	for (int i = 0; i < 4; i++)
		ret += total[i] * mul[i];
	return ret;
}
/*
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int ch[4], d[4];
		for (int i = 0; i < 4; i++)
			scanf("%d", &ch[i]);
		for (int i = 0; i < 4; i++)
			scanf("%d", &d[i]);
		printf("%d\n", calc_ab(ch, d));
	}
	return 0;
}*/

int main() {
	printf("%lld", 10000000000000ll);
	return 0;
}