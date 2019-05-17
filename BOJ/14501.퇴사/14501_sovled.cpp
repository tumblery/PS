#include<stdio.h>
#define MAX_N 15
int time[MAX_N], pay[MAX_N], N, ans;
int maxcmp(int a, int b) {
	return a > b ? a : b;
}
void solve(int day, int paymant,int prev_day) {
	if (day >= N) {
		if (day == N)ans = maxcmp(ans, paymant);
		else ans = maxcmp(ans, paymant-pay[prev_day]);
		return;
	}
	solve(day + 1, paymant,day);
	solve(day + time[day], paymant + pay[day],day);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &time[i], &pay[i]);
	ans = 0;
	solve(0, 0,-1);
	printf("%d", ans);
	return 0;
}