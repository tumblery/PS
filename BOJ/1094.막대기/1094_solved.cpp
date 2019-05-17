#include<stdio.h>
#include<queue>
#include<functional>
using namespace std;

int main() {
	int X;
	scanf("%d", &X);
	int ans,sum = 64;
	priority_queue<int,vector<int>,greater<int>> Q;
	Q.push(64);
	while (!Q.empty()) {
		if (sum == X) {
			ans = Q.size();
			break;
		}
		int tmp = Q.top();
		Q.pop();
		
		if (sum - tmp / 2 >= X) {
			Q.push(tmp / 2);
			sum -= tmp / 2;
		}
		else {
			Q.push(tmp / 2);
			Q.push(tmp / 2);
		}
	}
	printf("%d", ans);
}