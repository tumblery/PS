#include<stdio.h>
#include<vector>
#include<limits>
using namespace std;
typedef long long int ll;
ll num_list[11];
int operator_list[10];
ll Mans,mans;

ll max_(ll a, ll b) {
	return a > b ? a : b;
}
ll min_(ll a, ll b) {
	return a < b ? a : b;
}
void calc(int N) {
	ll tmp = num_list[0];
	for (int i = 0; i < N-1 ; i++) {
		switch (operator_list[i])
		{
		case 0://µ¡¼À
			tmp += num_list[i + 1];
			break;
		case 1://»¬¼À
			tmp -= num_list[i + 1];
			break;
		case 2://°ö¼À
			tmp *= num_list[i + 1];
			break;
		case 3://³ª´°¼À
			if (tmp < 0) {
				tmp *= -1;
				tmp /= num_list[i + 1];
				tmp *= -1;
			}
			else {
				tmp /= num_list[i + 1];
			}
		default:
			break;
		}
	}
	mans = min_(mans, tmp);
	Mans = max_(Mans, tmp);
}

void permutation(int idx, int N) {
	if (idx == N - 1) {
		return calc(N);
	}

	for (int i = idx; i < N-1; i++) {
		int tmp = operator_list[i];
		operator_list[i] = operator_list[idx];
		operator_list[idx] = tmp;
		
		permutation(idx+1, N);
		
		tmp = operator_list[i];
		operator_list[i] = operator_list[idx];
		operator_list[idx] = tmp;
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num_list[i]);
	int tmp,I=0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &tmp);
		while (tmp--) {
			operator_list[I++] = i;
		}
	}
	mans = numeric_limits<ll>::max();
	Mans = numeric_limits<ll>::min();
	permutation(0, N);
	printf("%lld\n%lld", Mans, mans);
	return 0;
}