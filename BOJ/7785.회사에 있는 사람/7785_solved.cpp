#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAX_TB 5000000
char people[1000001][6] = { 0, };
bool enter[1000001] = { false, };
int map[5000001];
string ans[1000000];
void init() {
	for (int i = 0; i <= MAX_TB; i++)
		map[i] = -1;
}
bool my_strcmp(char* a, char* b) {
	while (*a == *b && *a) {
		*a++;
		*b++;
	}
	if (*a == *b)return true;
	else return false;
}
void my_strcpy(char* dst, char*src) {
	int c,i;
	i = 0;
	while (src[i] != 0) {
		dst[i] = src[i];
		i++;
	}
}
void my_strcpy(int idx, char* str) {
	int c =0;
	ans[idx] = "";
	while (str[c] != 0) {
		ans[idx] += str[c];
		c++;
	}
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
	for (int i = 0; i <= MAX_TB; i++) {
		if (map[hash] == -1) {
			map[hash] = idx;
			return;
		}
		hash++;
		if (hash > MAX_TB)hash = 0;
	}

}
int find_hash(char*str) {
	int hash = get_hash(str);
	for (int i = 0; i <= MAX_TB; i++) {
		if (map[hash] == -1)return -1;
		if (my_strcmp(str, people[map[hash]]))return map[hash];
		hash++;
		if (hash > MAX_TB)hash = 0;
	}
	return -1;
}
int main() {
	int N,P,num;
	P = 0;
	scanf("%d", &N);
	init();
	for (int i = 0; i < N; i++) {
		char tmp[6] = { 0, }, command[10] = { 0, };
		scanf("%s", tmp);
		num = find_hash(tmp);
		if (num == -1) {
			push_hash(tmp, P);
			my_strcpy(people[P], tmp);
			num = P;
			P++;
			
		}
		getchar();
		scanf("%s", command);
		if (my_strcmp(command, "enter"))enter[num] = true;
		else enter[num] = false;
	}
	int idx = 0;
	for (int i = 0; i < P; i++) {
		if (enter[i])my_strcpy(idx++, people[i]);
	}
	sort(ans, ans + idx);
	for (int i = idx - 1; i >= 0; i--)
		cout << ans[i] << "\n";
	return 0;
}