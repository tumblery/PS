#include<stdio.h>
#include<malloc.h>
typedef struct run{
	int ability;
	int now;
};
run runners[500001];
int cnt[500001];
void init(int n) {
	for (int i = 0; i < n; i++)
		cnt[i] = 0;
}
void merge_sort(int st, int en) {
	if (st == en)return;
	merge_sort(st, (st+en) / 2);
	merge_sort((st + en) / 2 + 1, en);
	run *tmp = (run*)malloc(sizeof(run)*(en - st + 1));
	int idx = 0;
	int i = st;
	int j = (st + en) / 2 + 1;
	while (i <= (st + en) / 2 && j <= en) {
		if (runners[i].ability > runners[j].ability) {
			tmp[idx] = runners[i];
			if (i - idx - st>0)
				cnt[runners[i].now] += i - idx - st;
			i++;
		}
		else {
			tmp[idx] = runners[j];
			if (j - idx - st >0)
				cnt[runners[j].now] += j - idx - st;
			j++;
		}
		idx++;
	}
	while (i <= (st + en) / 2) {
		tmp[idx] = runners[i];
		if(i - idx - st>0)
			cnt[runners[i].now] += i - idx - st;
		i++;
		idx++;
	}
	while (j <= en) {
		tmp[idx] = runners[j];
		if(j - idx - st >0)
			cnt[runners[j].now] += j - idx - st;
		j++;
		idx++;
	}
	for (int idx=0,i = st; i <= en; idx++,i++) {
		runners[i] = tmp[idx];
	}
	free(tmp);
}
int main() {
	int N;
	int now;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &now);
		runners[i] = { now,i};
	}
	init(N);
	merge_sort(0, N - 1);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", i - cnt[i-1]);
	}
	return 0;
}