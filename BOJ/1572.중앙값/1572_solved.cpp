#include<stdio.h>
#define MAX 65536
typedef long long int ll;
int tree[300000];
int input[250000];
ll ans,St;

void init() {
	for (int i = 0; i < 300000; i++)
		tree[i] = 0;
	St = MAX*2;
}

void update(int node, int diff) {
	while (node >= 1) {
		tree[node] += diff;
		node /= 2;
	}
}

int get_index(int node, int k,int st,int en) {
	if (tree[node] >= k &&  st == en)
		return st;
	if (tree[node * 2] >= k) {
		return get_index(node * 2, k, st, (st + en) / 2);
	}
	else {
		k -= tree[node * 2];
		return get_index(node * 2 + 1, k, (st + en) / 2 + 1, en);
	}
}

int main() {
	int N, K,tmp,f;
	scanf("%d%d", &N, &K);
	f = (K + 1) / 2;
	ans = 0;
	init();
	for (int i = 0; i < K; i++) {
		scanf("%d", &input[i]);
		update(St + input[i], 1);
	}
	ans += (ll)get_index(1, f, 0, St - 1);
	for (int i = K; i < N; i++) {
		scanf("%d", &input[i]);
		update(St + input[i - K], -1);
		update(St + input[i], 1);
		ans += (ll)get_index(1, f, 0, St - 1);
	}
	printf("%lld", ans);
	return 0;
}
	