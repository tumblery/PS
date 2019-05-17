#include<stdio.h>
int isPrime[123457*2] = { 0, }, Prime[123457*2], idx;

void init() {
	idx = 1;
	for (int i = 2; i <= 123456*2; i++) {
		if (isPrime[i] == 0) {
			isPrime[i] = 1;
			Prime[i] = idx;
			idx++;
			for (int j = i * 2; j <= 123456*2; j += i)
				isPrime[j] = 1;
		}
		else {
			Prime[i] = idx - 1;
		}
	}
}

int main() {
	init();		
	int N;
	while (1) {
		scanf("%d", &N);
		if (N == 0)break;
		printf("%d\n",Prime[N*2]-Prime[N]);
	}
	return 0;
}