#include<stdio.h>
typedef long long int ll;


int main() {
	ll S;
	scanf("%lld", &S);
	int N = 1;
	while (1ll * N*(N + 1) / 2 <= S)
		N++;
	printf("%d", N - 1);
	return 0;
}