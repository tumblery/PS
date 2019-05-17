#include<stdio.h>
typedef long long int ll;
ll total,N[51],K;
int M;
double P[51];

int main() {
	scanf("%d", &M);
	total = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%lld", &N[i]);
		total += N[i];
		
	}
	scanf("%lld", &K);
	double ans = 0.0;
	for (int i = 1; i <= M; i++) {
		if (N[i] >= K) 
		{
			P[i] = 1.0;
			for (int j = 0; j < K; j++) {
				P[i] *= (double) (N[i] - (ll)j)/(total - (ll)j);
			}
		}
		ans += P[i];
	}
	printf("%.15lf", ans);
}