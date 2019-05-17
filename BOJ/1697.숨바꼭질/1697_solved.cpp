#include<stdio.h>
#include<utility>
#include<queue>
using namespace std;
bool visited[100001] = { false, };
int Me, S;

int main() {
	scanf("%d%d", &Me, &S);
	int ans;
	queue<pair<int,int>> Q;
	Q.push({ Me,0 });
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		if (visited[now.first])continue;
		if (now.first == S) {
			ans = now.second;
			break;
		}
		visited[now.first] = true;

		int ni;
		ni = now.first + 1;
		if (ni <= 100000)
			Q.push({ ni,now.second + 1 });
		ni = now.first - 1;
		if (ni >= 0)
			Q.push({ ni,now.second + 1 });
		ni =now.first*2;
		if (ni >= 0 && ni <= 100000)
			Q.push({ ni,now.second + 1 });
	}
	printf("%d", ans);
	return 0;
}