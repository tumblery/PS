#include<stdio.h>
typedef long long int ll;
const int total = 1048575;
ll candyTree[2100000] = { 0, };
int popCandy(int st, int en, int now, int idx) {
	if (st == en && candyTree[now] > 0)return st;
	if (candyTree[now*2] < idx) {
		return popCandy((st + en) / 2 + 1, en, now * 2 + 1, idx - candyTree[now * 2]);
	}
	else {
		return popCandy(st, (st + en) / 2, now * 2, idx);
	}
}
void Candy(int st, int en, int now, int idx,int diff) {
	if (idx < st || en < idx)return;
	if (st == en)
		return;
	candyTree[now] += diff;
	Candy(st, (st + en) / 2, now * 2, idx, diff);
	Candy((st + en) / 2 + 1, en, now * 2 + 1, idx, diff);
}
int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int A, B;
		scanf("%d", &A);
		if (A == 1) {//B번째 사탕 한개 빼기
			scanf("%d", &B);
			int ans = popCandy(1, total, 1, B);
			printf("%d\n", ans);
			candyTree[total + ans]--;
			Candy(1, total, 1, ans, -1);
		}
		if (A == 2) {//B의 수의 사탕 C개 더하기
			ll C;
			scanf("%d%lld", &B, &C);
			candyTree[total + B] += C;
			Candy(1, total, 1, B, C);
		}

	}
	return 0;
}