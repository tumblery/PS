#include<stdio.h>
#define HASH 3001
char cypher[1001][11];
char ans[1001][11];
int hashlist[3002];
int map[1001];

void init() {
	for (int i = 0; i <= HASH; i++)
		hashlist[i] = -1;
}
bool str_cmp(char* a, char* b) {
	while (*a == *b && *a != 0) {
		*a++;
		*b++;
	}
	if (*a == *b)return true;
	else return false;
}
void str_cpy(char* dst, char* src) {
	int i = 0;
	while (src[i] != 0) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}
int get_hash(char* str) {
	int hash = 1234;
	int c;
	while (c = *str++) {
		hash = ((hash >> 5) + hash) % HASH + c - 'A';
		hash %= HASH;
	}
	return hash%HASH;
}

void push_hash(char* str,int idx) {
	int hash = get_hash(str);
	for (int i = 0; i <= HASH; i++) {
		if (hashlist[hash] == -1) {
			hashlist[hash] = idx;
			return;
		}
		hash++;
		if (hash > HASH)hash = 0;
	}
}

int find_hash(char* str) {
	int hash = get_hash(str);
	for (int i = 0; i <= HASH; i++) {
		if (hashlist[hash] == -1)return -1;
		if (str_cmp(cypher[hashlist[hash]], str))return hashlist[hash];
		hash++;
		if (hash > HASH)hash = 0;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		char tmp[11];
		int N;
		init();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", cypher[i]);
			getchar();
			push_hash(cypher[i],i);
		}
		for (int i = 0; i < N; i++) {
			scanf("%s", tmp);
			getchar();
			map[i] = find_hash(tmp);
		}
		
		for (int i = 0; i < N; i++) {
			scanf("%s", tmp);
			getchar();
			str_cpy(ans[map[i]], tmp);
		}
		for (int i = 0; i < N; i++)
			printf("%s ", ans[i]);
		printf("\n");
	}
	return 0;
}