#include<stdio.h>
typedef long long int ll;
typedef struct pos {
	ll x, y;
};
typedef struct circle {
	pos center;
	ll R;
};
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		pos st, en;
		circle C;
		scanf("%lld%lld%lld%lld", &st.x, &st.y, &en.x, &en.y);
		bool is_in_st, is_in_en;
		int n,ans;
		scanf("%d", &n);
		ans = 0;
		while (n--) {
			scanf("%lld%lld%lld", &C.center.x, &C.center.y, &C.R);
			if ((C.center.x - st.x)*(C.center.x - st.x) + (C.center.y - st.y)*(C.center.y - st.y) < C.R*C.R)is_in_st = true;
			else is_in_st = false;
			if ((C.center.x - en.x)*(C.center.x - en.x) + (C.center.y - en.y)*(C.center.y - en.y) < C.R*C.R)is_in_en = true;
			else is_in_en = false;
			if (is_in_en != is_in_st) ans++;
		}
		printf("%d\n", ans);
	}
}