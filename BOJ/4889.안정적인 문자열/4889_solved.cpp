#include<stdio.h>
char input[2001], str[2001],stack[2001];
int top;
char pop() {
	return stack[--top];
}
void push(char c) {
	stack[top++] = c;
}
bool is_Empty() {
	if (top <= 0)return true;
	else return false;
}
int str_len(char* str) {
	int size = 0;
	while(*str++)size++;
	return size;
}
int main() {
	int cnt = 1;
	while (1) {
		scanf("%s", input);
		if (input[0] == '-')break;
		int size = str_len(input);
		top = 0;
		for (int i = 0; i < size; i++) {
			if (is_Empty()) {
				push(input[i]);
			}
			else {
				if (stack[top - 1] == '{' && input[i] == '}')pop();
				else push(input[i]);
			}
		}
		long long int ans = 0;
		for (int i = 0; i < top; i+=2) {
			if ( stack[i] == stack[i + 1])ans += 1;
			else ans += 2;
		}
		printf("%d. %lld\n", cnt, ans);
		cnt++;
	}
}