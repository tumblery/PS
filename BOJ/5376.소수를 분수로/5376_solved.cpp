#include<stdio.h>
#include<map>
typedef long long int ll;
ll gcd(ll A, ll B) {
	if (A < B)return gcd(B, A);
	ll r;
	while ((r = A%B) != 0) { A = B; B = r; }
	return B;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		char input[100] = { 0, };
		scanf("%s", input);
		ll x1, x2, y1, y2;
		x1 = x2 = 0;
		y1 = y2 = 1;
		int idx = 2;
		while (input[idx] != 0 && input[idx] != '(') {
			x1 = x1 * 10 + (input[idx] - '0');
			y1 *= 10;
			idx++;
		}
		if (input[idx] == '(') {
			idx++;
			while (input[idx] != 0 && input[idx] != ')') {
				x2 = x2 * 10 + (input[idx] - '0');
				y2 *= 10;
				idx++;
			}
			y2--;
		}
		ll A, B;
		A = x1*y2 + x2;
		B = y1*y2;
		ll GCD = gcd(A, B);
		printf("%lld/%lld\n", A / GCD, B / GCD);
	}
}