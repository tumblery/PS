#include<stdio.h>

typedef struct n {
	int medal[3];
	int code;
	bool operator <(const n& a)const {
		return (medal[0] == a.medal[0] ? (medal[1] == a.medal[1]? medal[2] < a.medal[2] :medal[1]<a.medal[1]):medal[0] < a.medal[0]);
	}
	bool operator ==(const n& a)const {
		return (medal[0] == a.medal[0] && medal[1] == a.medal[1] && medal[2] == a.medal[2]);
	}
};

n list[1001];

void sort(int f, int l) {
	int pivot;
	int i, j;
	n tmp;
	if (f < l) {
		pivot = f;
		i = f;
		j = l;
		while (i < j) {
			while ((list[i] < list[pivot] || list[i] == list[pivot])&& i < l)
				i++;
			while (list[pivot] < list[j])
				j--;
			if (i < j) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
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
	int N,K;
	scanf("%d%d", &N,&K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i].code);
		for (int j = 0; j < 3; j++)
			scanf("%d", &list[i].medal[j]);
	}
	sort(0, N - 1);
	int ranking[1000];
	ranking[N-1] = 1;
	int flag = 1;
	for (int i = N-2; i >=0; i--) {
		if (list[i + 1] == list[i]) {
			ranking[i] = ranking[i + 1];
			flag++;
		}
		else {
			ranking[i] = ranking[i + 1] + flag;
			flag = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (list[i].code == K) {
			printf("%d", ranking[i]);
			return 0;
		}
	}
}