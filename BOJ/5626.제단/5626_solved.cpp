#include<stdio.h>
#define MOD 1000000007
typedef long long int ll;
ll dp[2][10001];
int tall[10001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tall[i]);
		if (tall[i] > (N-1) / 2)
		{
			printf("0");
			return 0;
		}
	}
	int height = (N-1) / 2;
	for (int i = 0; i < N; i++)dp[0][i] = 0;
	if (tall[0] == 0 || tall[0] == -1)
		dp[0][0] = 1;
	for (int i = 1; i < N; i++) {
		int prev= (i - 1) % 2;
		int now = i % 2;
		if (tall[i] == -1) {
			for (int j = 0; j <= height; j++) {			
 				if (j - 1 >= 0)dp[now][j] = (dp[prev][j]+dp[prev][j - 1]+dp[prev][j+1])%MOD;
				else dp[now][j] = (dp[prev][j]+dp[prev][j+1])%MOD;
			}
		}
		else {
			for (int j = 0; j <= height; j++) {
				dp[now][j] = 0;
			}			
			if (tall[i] - 1 >= 0)dp[now][tall[i]] = (dp[prev][tall[i]]+dp[prev][tall[i] - 1]+dp[prev][tall[i]+1])%MOD;
			else dp[now][tall[i]] = (dp[prev][tall[i]]+ dp[prev][tall[i]+1])%MOD;
		}
	}
	printf("%lld", dp[(N - 1) % 2][0]);
	return 0;
}