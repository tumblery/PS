#include<stdio.h>

int score[8][2];

void sort(int f,int l) {
	int pivot;
	int i;
	int j;
	int tmp[2];
	if (f < l) {
		pivot = f;
		i = f;
		j = l;
		while (i < j) {
			while (score[i][0] <= score[pivot][0] && i < l) {
				i++;
			}
			while (score[j][0] > score[pivot][0]) {
				j--;
			}
			if (i < j) {
				tmp[0] = score[i][0];
				tmp[1] = score[i][1];
				score[i][0] = score[j][0];
				score[i][1] = score[j][1];
				score[j][0] = tmp[0];
				score[j][1] = tmp[1];
			}
		}
		tmp[0] = score[pivot][0];
		tmp[1] = score[pivot][1];
		score[pivot][0] = score[j][0];
		score[pivot][1] = score[j][1];
		score[j][0] = tmp[0];
		score[j][1] = tmp[1];
		sort(f, j - 1);
		sort(j + 1, l);
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &score[i][0]);
		score[i][1] = i + 1;
	}
	sort(0,7);
	int sum = 0;
	int ans[9] = { 0, };
	for (int i = 7; i >= 3; i--) {
		sum += score[i][0];
		ans[score[i][1]] = 1;
	}
	printf("%d\n", sum);
	for (int i = 0; i < 9; i++) {
		if (ans[i] == 1)printf("%d ", i);
	}
	return 0;
}