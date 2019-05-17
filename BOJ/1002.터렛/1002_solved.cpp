#include<stdio.h>
#include<memory.h>
typedef long long int ll;
typedef struct circle {
	ll x, y, r;
	bool operator <(const circle& A)const {
		return r < A.r;
	}

}cir;
cir input[2];
void swap(cir *A, cir *B) {
	cir tmp;

	tmp.x = A->x;
	tmp.y = A->y;
	tmp.r = A->r;

	A->r = B->r;
	A->x = B->x;
	A->y = B->y;

	B->r = tmp.r;
	B->x = tmp.x;
	B->y = tmp.y;

}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		
		for(int i=0;i<2;i++)
			scanf("%lld%lld%lld", &input[i].x, &input[i].y, &input[i].r);
		if (input[1] < input[0])
			swap(&input[0], &input[1]);
		//0이 작은 원 1이 큰원
		//작은원이 안에 있는지 밖에 있는지 판별한다.
		//1.작은 원이 안에 있는 경우
		ll len = (input[0].x - input[1].x)*(input[0].x - input[1].x) + (input[0].y - input[1].y)*(input[0].y - input[1].y);
		if (len == 0) {
			if (input[0].r == input[1].r)printf("-1\n");
			else printf("0\n");
			continue;
		}
		if (len < input[1].r*input[1].r) {
			if (len < (input[1].r - input[0].r)*(input[1].r - input[0].r)) {
				printf("0\n");
			}
			else if (len == (input[1].r - input[0].r)*(input[1].r - input[0].r)) {
				printf("1\n");
			}
			else {
				printf("2\n");
			}
		}
		
		else {
			if (len < (input[1].r + input[0].r)*(input[1].r + input[0].r)) {
				printf("2\n");
			}
			else if (len == (input[1].r + input[0].r)*(input[1].r + input[0].r)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}


		}
		
	}
	return 0;
}