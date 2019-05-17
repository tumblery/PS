#include<stdio.h>
typedef  struct node {
	int parent;
	int rchild;
	int lchild;
};

node Node[26];
void preorder(int now) {
	if (now == '.' - 'A')return;
	printf("%c", now + 'A');
	preorder(Node[now].lchild);
	preorder(Node[now].rchild);
}
void inorder(int now) {
	if (now == '.' - 'A')return;
	inorder(Node[now].lchild);
	printf("%c", now + 'A');
	inorder(Node[now].rchild);
}
void postorder(int now) {
	if (now == '.' - 'A')return;
	postorder(Node[now].lchild);
	postorder(Node[now].rchild);
	printf("%c", now + 'A');
	
}
int main() {
	int N;
	scanf("%d", &N);
	
	while (N--) {
		char input[10];
		getchar();
		scanf("%[^\n]s", input);
		Node[input[0] - 'A'].lchild = input[2] - 'A';
		Node[input[0] - 'A'].rchild = input[4] - 'A';
		Node[input[2] - 'A'].parent = input[0] - 'A';
		Node[input[4] - 'A'].parent = input[0] - 'A';
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
	return 0;
}