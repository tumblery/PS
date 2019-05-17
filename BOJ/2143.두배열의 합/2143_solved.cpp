#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
int T, tmp, A[1002], B[1002];
int sum_A[505001];
int binary_search_fr(int N, int target) {
	int ret, lo, hi, mid;
	lo = 0;
	hi = N-1;
	ret = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (sum_A[mid] == target) {
			ret = mid;
			hi = mid - 1;
		}
		else if (sum_A[mid] > target) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ret;
	
}
int binary_search_be(int N, int target) {
	int ret, lo, hi, mid;
	lo = 0;
	hi = N - 1;
	ret = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (sum_A[mid] == target) {
			ret = mid;
			lo = mid + 1;
		}
		else if (sum_A[mid] > target) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ret;
}
int main() {
	int n, m, idx;
	
	scanf("%d", &T);
	scanf("%d", &n);
	idx = 0;
	A[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		A[i] += A[i - 1];
		for (int j = i - 1; j >= 0; j--) {
			sum_A[idx] = A[i] - A[j];
			idx++;
		}
	}
	sort(sum_A, sum_A + idx);
	B[0] = 0;
	scanf("%d", &m);
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &B[i]);
		B[i] += B[i - 1];
		for (int j = i - 1; j >= 0; j--) {
			int be = binary_search_be(idx, T - (B[i] - B[j]));
			int fr = binary_search_fr(idx, T - (B[i] - B[j]));
			if(be != -1)
				ans += be-fr+1;
		}
	}
	printf("%lld", ans);
	return 0;
}