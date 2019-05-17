#include<stdio.h>
#include<string.h>

int head, tail;
int queue[100000];
void push(int x) {
	queue[tail++] = x;
}
int pop() {
	if (head == tail) return -1;
	int ret = queue[head];
	head++;
	return ret;
}
int size() {
	return tail-head;
}
int empty() {
	if (head == tail)return 1;
	return 0;
}
int front() {
	if (head == tail)return -1;
	return queue[head];
}
int back() {
	if (head == tail)return -1;
	return queue[tail-1];
}
int main() {
	head = tail = 0;
	int N;
	scanf("%d", &N);
	while (N--) {
		char command[10];
		scanf("%s", command);
		if (!strcmp(command ,"push")) {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(command, "front")) {
			printf("%d\n", front());
		}
		else if (!strcmp(command, "back")) {
			printf("%d\n", back());
		}
	}
}