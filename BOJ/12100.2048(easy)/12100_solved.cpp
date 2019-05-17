#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;

typedef struct info{
	int board[20][20];
	int depth;
	int MAX;
};
int ret_b[20][20];
int input[20][20];
info move_r(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = size - 1;
		for (int j = size-1; j >=0; j--) {
			if (n.board[i][j] > 0) {
				ret.board[i][cnt--] = n.board[i][j];
			}
		}
	}
	return ret;
}
info sum_r(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = size - 1;
		for (int j = size - 1; j >= 0; j--) {
			if (j>0&& n.board[i][j] > 0 && n.board[i][j] == n.board[i][j - 1])
			{
				ret.board[i][cnt--] = n.board[i][j] * 2;
				j--;
			}
			else if (n.board[i][j] > 0) {
				ret.board[i][cnt--] = n.board[i][j];
			}

		}
	}
	return ret;
}
info move_l(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = 0;
		for (int j = 0; j < size; j++) {
			if (n.board[i][j] > 0) {
				ret.board[i][cnt++] = n.board[i][j];
			}
		}
	}
	return ret;
}
info sum_l(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = 0;
		for (int j = 0; j < size; j++) {
			if (j < (size-1) && n.board[i][j] > 0 && n.board[i][j] == n.board[i][j + 1])
			{
				ret.board[i][cnt++] = n.board[i][j] * 2;
				j++;
			}
			else if (n.board[i][j] > 0) {
				ret.board[i][cnt++] = n.board[i][j];
			}
		}
	}
	return ret;
}
info move_u(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = 0;
		for (int j = 0; j <size; j++) {
			if (n.board[j][i] > 0)
				ret.board[cnt++][i] = n.board[j][i];
		}
	}
	return ret;
}
info sum_u(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = 0;
		for (int j = 0; j < size -1; j++) {
			if (j < (size - 1) && n.board[j][i] > 0 && n.board[j][i] == n.board[j+1][i])
			{
				ret.board[cnt++][i] = n.board[j][i] * 2;
				j++;
			}
			else if (n.board[j][i] > 0) {
				ret.board[cnt++][i] = n.board[j][i];
			}
		}
	}
	return ret;
}
info move_d(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = size - 1;
		for (int j = size-1; j >= 0; j--) {
			if (n.board[j][i] > 0) {
				ret.board[cnt--][i] = n.board[j][i];
			}
		}
	}
	return ret;
}
info sum_d(info n, int size) {
	int cnt;
	info ret = n;
	memset(ret.board, 0, sizeof(ret.board));
	for (int i = 0; i < size; i++) {
		cnt = size - 1;
		for (int j = size-1; j >=0; j--) {
			if (j > 0 && n.board[j][i] > 0 && n.board[j][i] == n.board[j - 1][i]) {
				ret.board[cnt--][i] = n.board[j][i] * 2;
				j--;
			}
			else if (n.board[j][i] > 0)
				ret.board[cnt--][i] = n.board[j][i];
		}
	}
	return ret;
}
int main() {
	int N,M=0,sum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &input[i][j]);
			sum += input[i][j];
			M = M > input[i][j] ? M : input[i][j];
		}
	}
	queue<info> Q;
	info tmp;
	memcpy(tmp.board, input, sizeof(input));
	tmp.depth = 0;
	tmp.MAX = M;
	Q.push(tmp);
	int ans = 0;
	int temp_M;
	while (!Q.empty()) {
		info now = Q.front();
		Q.pop();
		if (now.depth > 5)break;
		ans = ans > now.MAX ? ans : now.MAX;
		if (ans == sum)break;
		temp_M = 0;
		tmp = sum_r(move_r(now,N), N);
		tmp.depth++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp_M = temp_M > tmp.board[i][j] ? temp_M : tmp.board[i][j];
		tmp.MAX = temp_M;
		Q.push(tmp);
		
		
		temp_M = 0;
		tmp = sum_l( move_l(now, N), N);
		tmp.depth++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp_M = temp_M > tmp.board[i][j] ? temp_M : tmp.board[i][j];
		tmp.MAX = temp_M;
		Q.push(tmp);

		temp_M = 0;
		tmp = sum_u(move_u(now, N), N);
		tmp.depth++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp_M = temp_M > tmp.board[i][j] ? temp_M : tmp.board[i][j];
		tmp.MAX = temp_M;
		Q.push(tmp);

		temp_M = 0;
		tmp = sum_d( move_d(now, N), N);
		tmp.depth++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp_M = temp_M > tmp.board[i][j] ? temp_M : tmp.board[i][j];
		tmp.MAX = temp_M;
		Q.push(tmp);
	}

	printf("%d", ans);
	return 0;
}