#include <vector>
#include <string>
#include <queue>
#include<stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;

const int MAX = 500;
const int INF = 987654321;
typedef struct
{
	int y, x;
}Dir;
Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
int N, M;
pair<int, int> start, destination;
string graph[MAX];
int dist[MAX][MAX];
queue<pair<int, int>> tree;
priority_queue < pair<int, pair<int, pair<int, int>>>> pq;
int main(void)
{
	scanf("%d%d", &N, &M);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++)
	{
		cin >> graph[i];
		for (int j = 0; j < M; j++)
			if (graph[i][j] == '+')
			{
				dist[i][j] = 0;
				tree.push({ i, j });
			}
			else if (graph[i][j] == 'V')
				start = { i, j };
			else if (graph[i][j] == 'J')
				destination = { i, j };
	}
	while (!tree.empty())
	{
		int y = tree.front().first;
		int x = tree.front().second;
		tree.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;
			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && dist[nextY][nextX] == -1)
			{
				dist[nextY][nextX] = dist[y][x] + 1;
				tree.push({ nextY, nextX });
			}
		}
	}
	pq.push({ dist[start.first][start.second],{ dist[start.first][start.second],{ start.first, start.second } } });
	while (!pq.empty())
	{
		int curY = pq.top().second.second.first;
		int curX = pq.top().second.second.second;
		int distance = pq.top().first;
		int minDistance = pq.top().second.first;
		pq.pop();
		if (curY == destination.first && curX == destination.second)
		{
			printf("%d", minDistance);
			break;
		}
		if (dist[curY][curX] == -1)
			continue;
		dist[curY][curX] = -1;
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveDir[i].y;
			int nextX = curX + moveDir[i].x;
			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && dist[nextY][nextX] != -1)
				pq.push({ dist[nextY][nextX],{ min(dist[nextY][nextX], minDistance),{ nextY, nextX } } });
		}
	}
	return 0;
}