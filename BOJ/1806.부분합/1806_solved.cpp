#include<stdio.h>
typedef long long int ll;
ll min(ll a, ll b) {
	return (a < b ? a : b);
}
int main() {
	ll N, S;
	ll sums[100001];
	scanf("%lld%lld", &N, &S);
	sums[0] = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &sums[i]);
	}
	ll sum,ans = 1000005;
	int left, right;
	sum = sums[0];
	left = right = 0;
	while (left <= right && right < N) {
		if (sum < S) {
			right++;
			sum += sums[right];
		}
		else {
			ans = min(ans, right - left + 1);
			sum -= sums[left];
			left++;
		}
	}
	if (ans > N)ans = 0;
	printf("%lld", ans);
}