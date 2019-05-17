#include<stdio.h>
#include<algorithm>
#include<limits>
using namespace std;
typedef long long int ll;
int A[4000], B[4000],C[4000],D[4000];
int AB[4000 * 4000+1], CD[4000 * 4000+1];
int AB_cnt[4000*4000+1],CD_cnt[4000*4000+1];
int binary_search_1(int size, int target) {
	int ret, hi, lo, mid;
	lo = 0;
	hi = size-1;
	ret = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (AB[mid] == target) {
			ret = mid;
			lo = mid + 1;
		}
		else if (AB[mid] > target)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return ret;
}
int binary_search_2(int size, int target) {
	int ret, mid, lo, hi;
	lo = 0;
	hi = size - 1;
	ret = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (CD[mid] == target) {
			ret = mid;
			lo = mid + 1;
		}
		else if (CD[mid] > target) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ret;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[idx++] = A[i] + B[j];
		}
	}
	sort(AB, AB + idx);
	idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			CD[idx++] = C[i] + D[j];
		}
	}
	sort(CD, CD + idx);
	int ABCNT = 1;
	int Base = AB[0];
	AB[idx] = numeric_limits<int>::min();
	for (int i = 1; i <= idx; i++) {
		if (Base == AB[i])ABCNT++;
		else {
			Base = AB[i];
			AB_cnt[i - 1] = ABCNT;
			ABCNT = 1;
		}
	}

	int CDCNT = 1;
	Base = CD[0];
	CD[idx] = numeric_limits<int>::min();
	for (int i = 1; i <= idx; i++) {
		if (Base == CD[i])CDCNT++;
		else {
			Base = CD[i];
			CD_cnt[i - 1] = CDCNT;
			CDCNT = 1;
		}
	}
 	ll ans = 0;
	Base = numeric_limits<int>::min();
	for (int i = 0; i < idx; i++) {
		if (Base == AB[i])continue;
		else {
			Base = AB[i];
			int ab = binary_search_1(idx, AB[i]);
			int cd = binary_search_2(idx, AB[i] * -1);
			if (ab == -1 || cd == -1)continue;
			ans += (ll)AB_cnt[ab] * CD_cnt[cd];
		}
	}
	printf("%lld", ans);
	return 0;
}