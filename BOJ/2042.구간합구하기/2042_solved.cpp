#include<stdio.h>
#include<limits>
#include<math.h>
typedef long long int ll;
int N,M,K,data_st;
ll tree[2100000];
ll get_sums(int st, int en,int lo,int hi,int now) {
	if (st <= lo && hi <= en)return tree[now];
	if (lo > en)return 0;
	if (hi < st)return 0;

	return get_sums(st, en, lo, (lo + hi) / 2, now * 2) + get_sums(st, en, (lo + hi) / 2 + 1, hi, now * 2 + 1);

}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	data_st = pow(2,((int)(log(N) / log(2)) + 1));
	for (int i = 0; i < N; i++) {
		scanf("%lld", &tree[data_st + i]);
		int tmp = data_st + i;
		while (tmp > 0) {
			tmp /= 2;
			tree[tmp] += tree[data_st + i];
		}
	}
	while ((M + K) > 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1) {
			M--;
			ll c;
			scanf("%lld", &c);
			ll sum = c -tree[data_st +b-1];
			int tmp = data_st + b - 1;
			while (tmp > 0) {
				tree[tmp] += sum;
				tmp /= 2;
			}

		}
		else if (a == 2) {
			K--;
			int c;
			scanf("%d", &c);
			printf("%lld\n",get_sums(b, c, 1, data_st, 1));
		}
	}
	return 0;

}