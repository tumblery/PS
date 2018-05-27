#include<stdio.h>
#include<malloc.h>
#define max(a,b) a>b?a:b
int main(void){
	int list[100001];
	int dp[100001];
	long long Max;
	int i,j,N,tmp;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&list[i]);
	}
	dp[0] = list[0];
	Max = dp[0];
	for(i=1;i<N;i++){
		dp[i] = max(dp[i-1]+list[i],list[i]);
		Max = max(Max,dp[i]);
	}
	printf("%lld",Max);
	return 0;
}