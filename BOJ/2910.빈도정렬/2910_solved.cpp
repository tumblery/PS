#include<stdio.h>
#define HASH 3007
int numlist[1001], count[1001],IDX[1001];
int map[3007+1],hidx;
typedef struct num {
	int cnt, n,f;
	bool operator <(const num& a)const {
		return cnt==a.cnt?f>a.f:cnt < a.cnt;
	}
	bool operator <=(const num& a)const {
		return cnt==a.cnt?f>=a.f:cnt <= a.cnt;
	}
};
num list[1001];
void init() {
	for (int i = 0; i < HASH + 1; i++)
		map[i] = -1;
	for (int i = 0; i < 1001; i++)
		count[i] = 0;
	hidx = 0;
}
int get_hash(int num) {
	return num%HASH;
}
int push_hash(int num) {
	int hash = get_hash(num);
	for (int i = 0; i <= HASH; i++) {
		if (map[hash] == -1) {
			map[hash] = hidx;
			numlist[hidx] = num;
			return hidx++;
		}
		hash++;
		if (hash > HASH)hash = 0;
	}
}
int find_hash(int num) {
	int hash = get_hash(num);
	for (int i = 0; i <= HASH; i++) {
		if (map[hash] == -1)return -1;
		if (numlist[map[hash]] == num)return map[hash];
		hash++;
		if (hash > HASH)hash = 0;
	}
}
void sort(int f, int l) {
	int i, j, pivot;
	num tmp;
	if (f < l) {
		i = f;
		j = l;
		pivot = i;
		while (i < j) {
			while (list[i] <= list[pivot] && i < l)i++;
			while (list[pivot] < list[j])j--;
			if (i < j) {
				tmp = list[j];
				list[j] = list[i];
				list[i] = tmp;
			}
		}
		tmp = list[pivot];
		list[pivot] = list[j];
		list[j] = tmp;
		sort(f, j - 1);
		sort(j + 1, l);
	}
}

int main() {
	int N, C,tmp;
	scanf("%d%d", &N, &C);
	init();
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i].n);
		tmp = find_hash(list[i].n);
		if (tmp == -1) {
			tmp = push_hash(list[i].n);
			IDX[tmp] = i;
		}
		count[tmp]++;
	}
	for (int i = 0; i < N; i++) {
		tmp = find_hash(list[i].n);
		list[i].cnt = count[tmp];
		list[i].f = IDX[tmp];
	}
	sort(0, N - 1);
	for (int i = N-1; i >= 0; i--)
		printf("%d ", list[i].n);
	return 0;
}