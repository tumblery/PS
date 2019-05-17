#include<stdio.h>
#define HASH 3000001
typedef long long int ll;
ll sums[200001];
ll ints[200001];
int cnt[200001];
int map[HASH+1];
int idx;

void init() {
	idx = 0;
	for (int i = 0; i <= HASH; i++)
		map[i] = -1;
	for (int i = 0; i < 200001; i++)
		ints[i] = cnt[i] = 0;
}

int get_hash(ll val) {
	int hash = 1234;
	if (val < 0) {
		val = val * -1;
		hash = 5678;
	}
	hash = ((hash >> 5) + hash) % HASH + (int)(val%HASH);
	return hash%HASH;
}

int push_hash(ll val) {
	int hash = get_hash(val);
	for (int i = 0; i <= HASH; i++) {
		if (map[hash] == -1) {
			map[hash] = idx;
			ints[idx++] = val;
			return idx-1;
		}
		hash++;
		if (hash > HASH)hash = 0;
	}
}
int find_hash(ll val) {
	int hash = get_hash(val);
	for (int i = 0; i <= HASH; i++) {
		if (map[hash] == -1) {
			return -1;
		}
		if (ints[map[hash]] == val)return map[hash];
		hash++;
		if (hash > HASH)hash = 0;
	}
	return -1;
}
int main() {
	
	int N, in;
	ll tmp, K;
	scanf("%d%lld", &N, &K);
	scanf("%lld", &sums[0]);
	for (int i = 1; i < N; i++) {
		scanf("%lld", &tmp);
		sums[i] = sums[i - 1] + tmp;
	}
	ll ans = 0;
	init();
	for (int i = 0; i < N; i++) {
		if (sums[i] == K)ans++;
		in = find_hash(sums[i] - K);
		if (in != -1) {
			ans += cnt[in];
		}
		in = find_hash(sums[i]);
		if (in == -1) {
			in = push_hash(sums[i]);
			cnt[in]++;
		}
		else {
			cnt[in]++;
		}
	}
	printf("%lld", ans);
	return 0;
}