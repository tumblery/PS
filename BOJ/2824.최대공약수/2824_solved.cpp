#include<stdio.h>

#define Mod 1000000000ll
#define P_Max 40000
#define N_Max 1000
typedef long long int ll;
bool Prime_candi[P_Max];
int Prime[P_Max], A_ch[P_Max], B_ch[P_Max];
int Acnt, Bcnt,Pcnt;
void get_P() {
	for (int i = 0; i < P_Max; i++)
		Prime_candi[i] = true;
	Pcnt = 0;
	A_ch[0] = A_ch[1] = 0;
	B_ch[0] = B_ch[1] = 0;
	for (int i = 2; i < P_Max; i++) {
		A_ch[i] = 0;
		B_ch[i] = 0;
		if (Prime_candi[i]) {
			Prime[Pcnt++] = i;
			Prime_candi[i] = false;
			for (int k = i * 2; k < P_Max; k += i)
				Prime_candi[k] = false;
		}
	}
	return;
}
int min(int A, int B) {
	return (A < B ? A : B);
}
int main() {
	int N, M;
	get_P();
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int j = 0; j < Pcnt; j++) {
			while (tmp%Prime[j] == 0) {
				A_ch[j]++;
				tmp /= Prime[j];
			}
			if (tmp <= 1)break;
		}
		if (tmp > 1) {
			Prime[Pcnt++] = tmp;
			A_ch[Pcnt - 1]++;
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int j = 0; j < Pcnt; j++) {
			while (tmp%Prime[j] == 0) {
				B_ch[j]++;
				tmp /= Prime[j];
			}
			if (tmp <= 1)break;
		}
		if (tmp > 1) {
			Prime[Pcnt++] = tmp;
			B_ch[Pcnt - 1]++;
		}
	}
	Acnt = Bcnt = 0;
	ll ans = 1;
	bool flag = false;
	for (int i = 0; i < Pcnt; i++) {
		int cnt = min(B_ch[i], A_ch[i]);
		for (int j = 0; j < cnt; j++) {
			ans *= (ll)Prime[i];
			if (ans > Mod) {
				ans %= Mod;
				flag = true;
			}
		}
	}
	if (flag)printf("%09lld", ans);
	else printf("%lld", ans);
	return 0;
}