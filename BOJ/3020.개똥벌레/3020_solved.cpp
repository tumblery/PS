#include<stdio.h>
#include<math.h>
const int max = 5000000;
int up[500001] = { 0, };
int down[500001] = { 0, };
int main() {
	int N, H,tmp ,upM,downM,ans,ans_c;	
	scanf("%d%d", &N, &H); 
	downM = upM = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		if (i%2 == 1) {
			down[tmp]++;
			if (tmp > downM)downM = tmp;
		}
		else {
			up[tmp]++;
			if (tmp > upM)upM = tmp;
		}
	}
	for (int i = upM; i >= 1; i--)
		up[i] += up[i + 1];
	for (int i = downM; i >= 1; i--)
		down[i] += down[i + 1];
	ans = max;
	ans_c = 0;
	for (int i = 1; i <= H; i++) {
		tmp = down[i] + up[H - i + 1];
		if (tmp < ans) {
			ans = tmp; ans_c = 0;
		}
		else if (tmp == ans)ans_c++;
	}
	printf("%d %d", ans, ans_c);
	
}