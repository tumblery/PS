#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
using namespace std;
typedef struct hats {
	int hat;
	int id;
	bool operator <(const hats& a)const {
		return hat == a.hat ? id < a.id : hat < a.hat;
	}
	bool operator <=(const hats& a)const {
		return hat == a.hat ? id <= a.id : hat <= a.hat;
	}
	bool operator ==(const hats& a)const {
		return hat == a.hat&&id == a.id;
	}
};

hats smaller[300010];
int P[300010],idx[10010];

int lower_bound(hats target, int size,int st,int en)
{
	int mid, start, end;
	start = st, end = en + 1;

	while (end > start)
	{
		mid = (start + end) / 2;
		if (target <= smaller[mid])
			end = mid;
		else start = mid + 1;
	}
	return end;
}
int upper_bound(hats target, int size,int  st,int en)
{
	int mid, start, end;
	start = st, end = en+1;

	while (end > start)
	{
		mid = (start + end) / 2;
		if (target < smaller[mid])
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int main() {
	int N, C, M;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		smaller[i] = { P[i],i };
	}
	/*
	FILE* fp,*out;
	fp = fopen("input.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(fp, "%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
	fscanf(fp, "%d", &P[i]);
	smaller[i] = { P[i],i };
	}*/
	sort(smaller, smaller + N);
	smaller[N] = { C+1,N };
	int prev = 0;
 	for (int i = 0; i <= N; i++) {
		if (prev != smaller[i].hat) {
			idx[smaller[i].hat] = i;
			prev = smaller[i].hat;
		}
	}
	
	scanf("%d", &M);
	//fscanf(fp, "%d", &M);
	srand(time(0));
	for (int i = 0; i < M; i++) {
		int a, b, ran, flag = 0;
		scanf("%d%d", &a, &b);
		//fscanf(fp, "%d%d", &a, &b);
		a--; b--;
		for (int j = 0; j < 500; j++) {
			ran = rand() % (b - a + 1) + a;
			int u = upper_bound({ P[ran],b }, N,idx[P[ran]],idx[P[ran]+1]);
			int l = lower_bound({ P[ran],a }, N,idx[P[ran]],idx[P[ran]+1]);
			int t = u - l;
			if ((smaller[u].id == b && smaller[l].id == a))t++;
			else if((smaller[u + 1].hat != P[ran] && smaller[l - 1].hat != P[ran])&&smaller[u].id <= b && smaller[l].id >= a)t++;
			if (t * 2 >(b - a + 1)) {
				flag = 1; break;
			}
		}
		if (flag == 1) {
			printf("yes %d\n", P[ran]);
			//fprintf(out, "yes %d\n", P[ran]);
		}
		else {
			printf("no\n");
			//fprintf(out, "no\n");
		}
	}
	return 0;
}