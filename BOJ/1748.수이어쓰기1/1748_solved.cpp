#include<stdio.h>
typedef long long int ll;
ll solve(ll N) {
	ll ans = 0;
	ll count = 10,cnt = 1;
	while (1) {
		if (N < count) {
			ans += (N - (count / 10) + 1)*cnt;
			break;
		}
		else {
			if (cnt == 1) ans += (count - 1)*cnt;
			else ans += (count-count/10)*cnt;
		}
		count *= 10;
		cnt++;
	}
	return ans;
}
int main() {
	ll N;
	scanf("%lld", &N);
	printf("%lld",solve(N));
	return 0;
}