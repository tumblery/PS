#include<stdio.h>

char A[5] = { 'D','C','B','A','E' };
int main() {
	int ans,tmp;
	for (int i = 0; i < 3; i++) {
		ans = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &tmp);
			ans += tmp;
		}
		printf("%c\n", A[ans]);
	}
	return 0;
}