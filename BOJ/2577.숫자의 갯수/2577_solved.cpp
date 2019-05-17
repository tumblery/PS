#include<stdio.h>
typedef long long int ll;
int list[10] = { 0, };
int main() {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	ll ans = a*b*c;
	while (ans > 0) {
		list[ans % 10]++;
		ans /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", list[i]);
	}
}