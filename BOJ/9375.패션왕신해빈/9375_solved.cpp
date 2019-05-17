#include<stdio.h>
#define MAXTB 103 
char kinds[30][21];
int clothes[30];
int map[103+1];

void init() {
	for (int i = 0; i < 30; i++) {
		clothes[i] = 0;
		for (int j = 0; j < 21; j++)
			kinds[i][j] = 0;
	}
	for (int i = 0; i < MAXTB; i++) {
		map[i] = -1;
	}
	return;
}
bool my_strcmp(char* a, char*b) {
	while (*a == *b && *a) {
		*a++;
		*b++;
	}
	if (*a == *b)return true;
	else return false;
}
void my_strcpy(char* dst, char* src) {
	int i = 0;
	while (src[i] != 0) {
		dst[i] = src[i];
		i++;
	}
	return;
}
int get_hash(char* str) {
	int hash = 26;
	int c;
	while (c = *str++) {
		hash = ((hash << 5) + hash) % MAXTB + c - 'a';
	}
	return (hash%MAXTB);
}
void push_hash(char* key, int val) {
	int hash = get_hash(key);
	for (int i = 0; i < MAXTB; i++) {
		if (map[hash] == -1) {
			map[hash] = val;
			return;
		}
		hash++;
		if (hash >= MAXTB)hash = 0;
	}
}

int find_hash(char* key) {
	int hash = get_hash(key);
	for (int i = 0; i < MAXTB; i++) {
		if (map[hash] == -1)return -1;
		if (my_strcmp(key, kinds[map[hash]]))return map[hash];
		hash++;
		if (hash >= MAXTB)hash = 0;
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		init();
		int N; 
		scanf("%d", &N);
		int idx = 0;
		for (int i = 0; i < N; i++) {
			char tmp[21] = { 0, }, K[21] = { 0, };
			scanf("%s", tmp);
			getchar();
			scanf("%s", K);
			int num = find_hash(K);
			if( num == -1) {
				push_hash(K, idx);
				num = idx;
				my_strcpy(kinds[idx], K);
				clothes[num]++;
				idx++;
			}
			else {
				clothes[num]++;
			}
		}
		int ans = 1;
		for (int i = 0; i < idx; i++) {
			ans *= (clothes[i] + 1);
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}