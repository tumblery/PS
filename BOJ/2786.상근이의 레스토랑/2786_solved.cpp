#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long int ll;
typedef struct food {
	ll f, s;
	bool operator<(const food& a)const {
		return s < a.s;
	}
};
ll min_[500001];
food menu[500001];
ll min__(ll a, ll b) {
	return a < b ? a : b;
}
int main() {
	int N;
	scanf("%d", &N);
	ll tmp;
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &menu[i].f,&menu[i].s);
	}
	sort(menu, menu + N);
	ll a =0;
	int j = 0;
	min_[N] = 1000000001ll;
	for (int i = N - 1; i >= 0; i--)
		min_[i] = min__(menu[i].f, min_[i + 1]);
	for (int i = 0; i < N; i++) {
		if (menu[j].s - menu[j].f < menu[i].s - menu[i].f)j = i;
		a += menu[i].s;
		printf("%lld\n", min__(a - menu[j].s + menu[j].f, a - menu[i].s + min_[i]));
	}
	return 0;
}