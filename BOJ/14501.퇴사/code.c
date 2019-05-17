#include<stdio.h>
#include<malloc.h>
#define MAX(a,b) a>b?a:b

typedef struct counsel{
	int T;
	int pay;
} Counsel;
int N;
int res = 0;
Counsel table[16];
void solve(int t,int p);	
int main(void){
	
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		scanf("%d %d",&table[i].T,&table[i].pay);
		if(i+table[i].T>N) table[i].pay = 0;
	}
	solve(0,0);
	printf("%d",res);
	
}

void solve(int t,int p){
	if(t == N){res = MAX(res,p);return;}

	if(t+table[t].T <= N){
		solve(t+table[t].T,p+table[t].pay);
	}
	if(t+1 <= N){
		solve(t+1,p);
	}
}