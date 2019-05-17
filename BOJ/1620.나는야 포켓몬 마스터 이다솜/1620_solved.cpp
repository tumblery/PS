#include<stdio.h>
#define MAX_TB 1000000
typedef  long long int ll;
char Monster[100001][21] = { 0, };
int map[1000001];

void init() {
	for (int i = 0; i < MAX_TB + 1; i++) {
		map[i] = -1;
	}
}
bool my_strcmp(char* a,char* b) {
	while (*a == *b && *a) {
		*a++;
		*b++;
	}
	if (*a == *b)return true;
	else return false;
}
int get_hash(char* str) {
	int hash = 25;
	int c;
	while (c = *str++) {
		hash = ((hash << 5) + hash) % MAX_TB + c;
	}
	return hash%MAX_TB;

}
void push_hash(char* str, int idx) {
	int hash = get_hash(str);
	for (int i = 0; i < MAX_TB + 1; i++) {
		if (map[hash] == -1) {
			map[hash] = idx;
			return;
		}
		hash++;
		if (hash > MAX_TB)hash = 0;
	}
}
int find_hash(char* str) {
	int hash = get_hash(str);
	for (int i = 0; i < MAX_TB + 1; i++) {
		if (map[hash] == -1)return -1;
		if (my_strcmp(str, Monster[map[hash]])) return map[hash];
		hash++;
		if (hash > MAX_TB)hash = 0;
	}
	return -1;
}
bool is_NUM(char* str) {
	int c;
	while (c = *str++) {
		if (c >= '0' && c <= '9')continue;
		return false;
	}
	return true;
}
int to_NUM(char* str) {
	int ans,c;
	ans = 0;
	while (c = *str++) {
		ans = ans * 10 + c - '0';
	}
	return ans;
}
int main() {
	int M, N;
	scanf("%d%d", &N, &M);
	init();
	for (int i = 1; i <= N; i++) {
		scanf("%s", Monster[i]);
		push_hash(Monster[i],i);
	}
	
	for (int i = 0; i < M; i++) {
		char Q[21] = { 0, };
		scanf("%s", &Q);
		if (is_NUM(Q)) {
			int num = to_NUM(Q);
			printf("%s\n", Monster[num]);
		}
		else {
			printf("%d\n", find_hash(Q));
		}
	}

	return 0;
}