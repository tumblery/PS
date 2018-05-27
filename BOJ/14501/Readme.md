# \#BOJ_14501번 퇴사
## Problem
![image](https://user-images.githubusercontent.com/20368859/40526981-db71d91a-6024-11e8-8587-9d2db238bd7e.png)

## Analyze
### first think
2중 매트릭스를 이용하여 최대 수익을 구해보자
#### example
![image](https://user-images.githubusercontent.com/20368859/40527109-7faa640c-6025-11e8-8213-a663b4489022.png)
위와 같이 **N=7**인 input이 주어졌을 때, dp[7][7]은 아래와 같이 표현될 수 있다.

![image](https://user-images.githubusercontent.com/20368859/40581950-7ec9be34-61a1-11e8-8214-7150d22e2efa.png)

 이제 각각의 날에서 벌수있는 최대의 금액의 날을 선택하여 돈을 벌어 나가면 된다. 즉 아래와 같이 계산을 해볼 수 있다.
1. i=0일때 첫날의 일을 착수하는 것이다. 이때 만약 첫날일을 착수하게 된다면 일당 받게 되는 돈은 3이 된다.
2. 그런데 그 다음날 즉, 둘째날이 될때 일당 받을 수 있는 돈을 보면 4이다 즉, 전날 보다 더 많은 돈을 받을 수 있다.
3. 그렇다면 둘째날의 페이를 선택하여 계산을 반복한다.
4. 만약 해당 날의 기간을 끝낸다면 다음 날의 일을 가지고 위의 계산을 반복한다.

#### 문제점
 만약 각 상담의 일당 페이가 같다면 해당 알고리즘은 문제를 가질 수 있다.
 ##### example
 ![image](https://user-images.githubusercontent.com/20368859/40582938-50ff8a84-61be-11e8-9f91-c5a28f444a23.png)

### Second think
**재귀적으로 생각해보자.**
우선 각각의 상담에 대한 내용을 아래와 같은 ==struct==로 구성하자.
```
typedef struct counsel{
	int T;
	int pay;
} Counsel;
```
상담에 대한 일정이나 내용은 list에 저장이 된다.
```
Counsel table[16];
```
만약 첫번째 날의 상담을 진행한다면 다음에 할수 있는 상담은 아래와 같이 표현 가능하다.
```
pay = 0;
pay += table[0].pay;
''''
next = table[0+table[0].T];
```
이를 착안하여 재귀 함수는 아래와 같이 구성이 가능하다.
```
void solve(int t,int p){
	if(t == N){res = MAX(res,p);return;}

	if(t+table[t].T <= N){
		solve(t+table[t].T,p+table[t].pay);
	}
	if(t+1 <= N){
		solve(t+1,p);
	}
}
```

