#include<stdio.h>
typedef struct node {
	int val;
	int rc, lc;
};
node Node[10001];
void PostOrder(int now) {
	if (Node[now].lc != -1)PostOrder(Node[now].lc);
	if (Node[now].rc != -1)PostOrder(Node[now].rc);
	printf("%d\n", Node[now].val);
}
int main() {
	int val, idx = 0;
	while (scanf("%d", &val) != EOF) {
//	while(1){
//		scanf("%d", &val);
		if (val == 0)break;
		Node[idx] = { val,-1,-1 };
		if (idx > 0) {
			int cur = 0;
			while (1) {
				if (Node[cur].val > Node[idx].val) {
					if (Node[cur].lc == -1) {
						Node[cur].lc = idx;
						break;
					}
					else {
						cur = Node[cur].lc;
					}
				}
				else {
					if (Node[cur].rc == -1) {
						Node[cur].rc = idx;
						break;
					}
					else {
						cur = Node[cur].rc;
					}
				}
			}
		}
		idx++;
	}
	PostOrder(0);
	return 0;
} 