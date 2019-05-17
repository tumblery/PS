#include<stdio.h>
#include<malloc.h>

typedef struct node {
	bool isEnd;
	bool isThere;
	node* words[60];
	node* next;
};

char list[60] = "!#$%&'()-0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZ^_`{}~=======";
node* head;

int str_len(char* str) {
	int len = 0;
	while (*str++)len++;
	return len;
}
int get_index(char a) {
	for (int i = 0; i < 60; i++)
		if (a == list[i])return i;
	return -1;
}
void append(char* str) {
	node* tmp = head;
	for (int i = 0; i < 100; i++) {
		int idx;
		if (str[i] >0 && (idx = get_index(str[i])) != -1) {
			if (tmp->words[idx] == NULL ) {
				node* n = (node*)malloc(sizeof(node));
				n->isEnd = false;
				for (int i = 0; i < 60; i++)n->words[i] = NULL;
				n->next = NULL;
				tmp->words[idx] = n;
			}
			tmp = tmp->words[idx];
		}
		else if (str[i] == '\\') {
			if (tmp->next == NULL) {
				node *n = (node*)malloc(sizeof(node));
				n->isEnd = false;
				for (int i = 0; i < 60; i++)n->words[i] = NULL;
				n->next = NULL;
				tmp->isEnd = true;
				tmp->next = n;
			}
			tmp = tmp->next;
		}
		else if(str[i] == 0) {
			tmp->isEnd = true;
			break;
		}
	}
}
void print(node* now,char* str,int idx, int depth) {
	if (now == NULL)return;
	if (now->isEnd) {
		for (int i = 0; i < depth; i++)printf(" ");
		printf("%s\n", str);
		char s[10] = { 0, };
		print(now->next, s, 0, depth + 1);
	}
	for (int i = 0; i < 60; i++) {
		if (now->words[i] != NULL) {
			str[idx] = list[i];
			print(now->words[i], str, idx + 1, depth);
			str[idx] = 0;
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);
	head = (node*)malloc(sizeof(node));
	head->isEnd = false;
	head->next = NULL;
	for (int i = 0; i < 60; i++)head->words[i] = NULL;
	for (int i = 0; i < N; i++) {
		char input[100] = { 0, };
		scanf("%s", input);
		append(input);
	}
	char tmp[10] = { 0, };
	print(head, tmp, 0, 0);
}