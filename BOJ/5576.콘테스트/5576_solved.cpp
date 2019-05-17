#include<stdio.h>

int W[10], H[10];

void sort(int list[], int left, int right) {
	int f, l,i,j, pivot, tmp;
	f = left;
	l = right;
	if (f < l) {
		pivot = f;
		while (f < l) {
			while (list[f] <= list[pivot] && f < right) {
				f++;
			}
			while (list[l] > list[pivot]) l--;
			if (f < l) {
				tmp = list[l];
				list[l] = list[f];
				list[f] = tmp;
			}
		}
		tmp = list[pivot];
		list[pivot] = list[l];
		list[l] = tmp;

		sort(list, left, l - 1);
		sort(list, l + 1, right);
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		scanf("%d", &W[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &H[i]);
	sort(W, 0, 9);
	sort(H, 0, 9);
	int ansW, ansH;
	ansH = ansW = 0;
	for (int i = 9; i >= 7; i--) {
		ansH += H[i];
		ansW += W[i];
	}

	printf("%d %d", ansW, ansH);
	return 0;
}