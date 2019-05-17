#include<stdio.h>
#define Max 21
typedef long long int ll;
ll fact[Max], K;
int N,op, ans[Max], visit[Max];
void init() {
	for (int i = 0; i < Max; i++) {
		ans[i] = 0;
		visit[i] = 0;
	}
	fact[0] = 1;
	for (int i = 1; i < Max; i++)
		fact[i] = fact[i - 1] * i;
}
int main() {
	init();
	scanf("%d", &N);
	scanf("%d", &op);
	if (op == 1) {//k번째 순열 탐색
		scanf("%lld", &K);
		int st = N - 1;
		int now;
		for (int i = 1; i <= N; i++) {
			int cnt = 1;
			for (int j = 1; j <= N; j++) {
				if (visit[j] == 1)continue;
				if (K <= fact[st] * cnt) {
					ans[i] = j;
					K -= (cnt - 1)*fact[st];
					st--;
					visit[j] = 1;
					break;
				}
				else cnt++;
			}
			if (K == 0) {
				if (ans[i] != 0)now = i + 1;
				else now = i;
				break;
			}
		}
		for (int i = N; i >= 1; i--) {
			if (visit[i] == 0)ans[now++] = i;
		}
		for (int i = 1; i <= N; i++)
			printf("%d ",ans[i]);
	}
	else if (op == 2) {//주어진 순열은 몇번째 순열인가
		for (int i = 1; i <= N; i++) {
			scanf("%d", &ans[i]);
		}
		K = 0;
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			visit[ans[i]] = 1;
			for (int j = 1; j <= N; j++) {
				if (j == ans[i])break;
				if (visit[j] == 1)continue;
				cnt++;
			}

			K += ((ll)cnt)*fact[N - i];
		}
		K++;
		printf("%lld", K);
	}
}