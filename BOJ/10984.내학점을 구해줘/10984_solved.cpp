#include<stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int t_case = 0; t_case < T; t_case++) {	
		double ans, tmp;
		int N, score,total;
		scanf("%d", &N);
		total = 0;
		ans = 0.0;
		for (int i = 0; i < N; i++) {
			scanf("%d %lf",&score, &tmp);
			ans += tmp*score;
			total += score;
		}
		ans /= total;
		printf("%d %.1lf\n", total, ans);
	}
	return 0;
}