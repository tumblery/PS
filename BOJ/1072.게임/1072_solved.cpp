#include<stdio.h>
typedef long long int ll;
int main() {
	ll X, Y, per,ans;
	scanf("%lld%lld", &X, &Y);
	per = (ll)((long double)(Y) / (long double)(X) * 100);
	if (per >= 99)printf("-1");
	else {
		ans = ((per + 1)*X - 100 * Y) / (99 - per);
		if (((per + 1)*X - 100 * Y) % (99 - per) != 0)
			ans++;
		printf("%lld", ans);
	}
	return 0;
}