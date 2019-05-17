#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
ll test(ll N) {
	ll ans = 0;
	for (ll i = 0; i <= N; i++) {
		ll tmp = i;
		while (tmp > 0) {
			ans += tmp % 10;
			tmp /= 10;
		}
	}
	return ans;
}
ll dp[16][150][2];
ll calc(int idx, int flag, vector<int> list, int sum) {
	if (idx < 0)return sum;
	ll &tmp = dp[idx][sum][flag];
	if (tmp != -1 && !flag)
		return tmp;
	ll ret = 0;
	int t = flag ? list[idx] : 9;
	for (int i = 0; i <= t; i++) {
		int nflag = (list[idx] == i) ? flag : 0;
		ret += calc(idx - 1, nflag, list, sum + i);
	}
	if (!flag)
		tmp = ret;
	return ret;
}
void init() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 150; j++) {
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -1;
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		ll A, B;
		scanf("%lld%lld", &A, &B);
		vector<int> a, b;
		A--;
		while (A) {
			a.push_back(A % 10);
			A /= 10;
		}
		while (B) {
			b.push_back(B % 10);
			B /= 10;
		}
		init();
		ll Aa = calc(a.size() - 1, 1, a, 0);
		ll Bb = calc(b.size() - 1, 1, b, 0);
		printf("%lld\n",  Bb-Aa );
	}
}