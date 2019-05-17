#include<stdio.h>

int main() {
	int list[26] = { 0, };
	int N;
	char name[35] = { 0, };
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		list[name[0] - 'a']++;
	}
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (list[i] >= 5) {
			flag = 1;
			printf("%c", 'a' + i);
		}
	}
	if (flag == 0)printf("PREDAJA");
}