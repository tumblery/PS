#include<stdio.h>

char A[101] = { 0, };
char B[101] = { 0, };
char ans[201] = { 0, };
char op;
int astr, bstr;
void add(char* a,int alen, int blen) {
	if (alen == blen) {
		ans[0] = '2';
		for (int i = 1; i < alen; i++)
			ans[i] = '0';
		ans[alen] = 0;
		return;
	}
	int plus = alen - blen;
	ans[0] = '1';
	for (int i = 1; i < alen; i++) {
		if (i == plus) ans[i] = '1';
		else ans[i] = '0';
	}
	ans[alen] = 0;
	return;
}
void mul(char* a, char *b) {
	ans[0] = '1';
	int zero = astr + bstr - 2;
	for (int i = 1; i <= zero; i++)ans[i] = '0';
	ans[zero + 1] = 0;
}
int str_len(char* str) {
	int ans = 0;
	int c;
	while ((c = *str++)) {
		ans++;
	}
	return ans;
}
int main() {
	scanf("%[^\n]s", &A);
	getchar();
	scanf("%c", &op);
	getchar();
	scanf("%s", &B);
	astr = str_len(A);
	bstr = str_len(B);
	if (op == '+') {
		if (astr > bstr) add(A, astr, bstr);
		else add(B, bstr, astr);
	}
	else {
		mul(A, B);
	}
	printf("%s", ans);
}