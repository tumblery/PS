#include<stdio.h>
#define MAX 100000
typedef long long int ll;
int Tree[400000],input[100001],L[100001],G[100001];
int ST = 1 << 17;
void init() {
	for (int i = 0; i < 400000; i++)
		Tree[i] = 0;
}
void update(int idx, int diff) {
	while (idx >= 1) {
		Tree[idx] += diff;
		idx /= 2;
	}
}
int find_sum(int node, int st, int en, int l, int r) {
	if (st <= l && r <= en)return Tree[node];
	if (en < l || st > r)return 0;
	int ret = find_sum(node * 2, st, en, l, (l + r) / 2) + find_sum(node * 2+1, st, en, (l + r) / 2 + 1, r);
	return ret;
}
int main() {
	init();
	ll ans = 0;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		G[i] = find_sum(1, input[i] + 1, N+1, 1, ST);
		update(ST + input[i]-1,1);
	}
	init();
	for (int i = N - 1; i >= 0; i--) {
		if (input[i] == 1)L[i] = 0;
		else L[i] = find_sum(1, 1, input[i]-1,1,ST);
		update(ST + input[i]-1, 1);
	}
	for (int i = 0; i < N; i++) {
		ans += 1ll* L[i] * G[i];
	}
	printf("%lld", ans);
	return 0;
}