#include<stdio.h>

int ans, N;
int ability[20][20];

int abs(int a) {
	return a > 0 ? a : a*-1;
}
int min(int a, int b) {
	return a < b ? a : b;
}
void calc_minus(bool team[]) {
	if (ans == 0)return;
	int A, B;
	A = B = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (team[i] && team[i] == team[j])
				A += ability[i][j];
			if (!team[i] && team[i] == team[j])
				B += ability[i][j];
		}
	}
	ans = min(ans, abs(A - B));
}

void comb(bool team[], int sel, int idx) {
	if (ans == 0)return;
	if (sel == N / 2) {
		return calc_minus(team);
	}
	if (idx >= N)return;
	comb(team, sel, idx + 1);
	team[idx] = true;
	comb(team, sel + 1, idx + 1);
	team[idx] = false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &ability[i][j]);
		}
	}
	bool team[20] = { false, };
	ans = 987654321;
	comb(team, 0, 0);
	printf("%d", ans);
}