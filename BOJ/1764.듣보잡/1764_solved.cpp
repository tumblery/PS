#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long int ll;
const int MAX_TB = 100000;

char listen[500000][21] = { 0, };
string ans[500000];
int map[1000001];

void init() {
	for (int i = 0; i < 1000001; i++)
		map[i] = -1;
}

int get_hash(char* str) {
	int hash = 26;
	int c;
	while (c = *str++) {
		c = c - 'a';
		hash = ((hash << 5) + hash) + c;
		hash %= MAX_TB;
	}
	return (int)(hash%MAX_TB);
}
void push_hash(char* str,int idx) {
	int hash = get_hash(str);
	for (int i = 0; i < 1000001; i++) {
		if (map[hash] == -1) {
			map[hash] = idx;
			return;
		}
		else {
			hash++;
			if (hash > MAX_TB)
				hash = 0;
		}
	}
}
bool my_strcmp(char* a, char* b) {
	int i=0;
	while (a[i] == b[i] && a[i] != 0) { i++; }
	if (a[i] == b[i])return true;
	else return false;
}
bool find_hash(char* str) {
	int hash = get_hash(str);
	for (int i = 0; i < 1000001; i++) {
		if (map[hash] == -1)return false;
		if (my_strcmp(listen[map[hash]], str))return true;
		hash++;
		if (hash > MAX_TB)hash = 0;
	}
}
void mystrcpy(int idx, char* src) {
	int i = 0;
	ans[idx] = "";
	while (src[i] != 0) {
		ans[idx] += src[i];
		i++;
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	getchar();
	init();
	for (int i = 0; i < N; i++) {
		scanf("%s", listen[i]);
		push_hash(listen[i],i);
	}
	int idx = 0;
	for (int i = 0; i < M; i++) {
		char tmp[20] = { 0, };
		scanf("%s", tmp);
		if (find_hash(tmp))mystrcpy(idx++,tmp);
	}
	printf("%d\n", idx);
	sort(ans, ans + idx);
	for (int i = 0; i < idx; i++) {
		cout << ans[i]<<'\n';
	}
	return 0;
}