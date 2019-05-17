#include<stdio.h>
#include<math.h>
double pos[21][2],ax,ay,ans;
int N;
double min_(double a, double b) {
	return a < b ? a : b;
}
void solve(int idx, int sel,double x,double y) {
	if (sel == N / 2) {
		double tmp = 0.0;
		tmp += (ax - x*2)*(ax - x*2);
		tmp += (ay - y*2)*(ay - y*2);
		tmp = sqrtl(tmp);
		ans = min_(ans, tmp);
		return;
	}
	if (idx >= N)return;
	solve(idx+1, sel, x, y);
	solve(idx + 1, sel + 1, x + pos[idx][0], y + pos[idx][1]);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		N;
		scanf("%d", &N);
		ax = ay = 0.0;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);
			ax += pos[i][0];
			ay += pos[i][1];
		}
		ans = 987654321.0;
		solve(0, 0, 0.0, 0.0);
		printf("%.7lf\n", ans);
	}
	return 0;
}