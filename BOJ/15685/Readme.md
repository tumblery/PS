# \#BOJ_15685번 드래곤 커브
## Problem
![image](https://user-images.githubusercontent.com/20368859/40582985-8fe7f9ba-61bf-11e8-9688-ddc7a78c798e.png)


## Analyze
해당 문제는 두 단계로 나누어 고민할 수 있다.

**1. 각 세대의 드래곤 커브 생성**
**2. 1x1인 정사각형의 네꼭지점 포함 확인**

 우선, 2의 문제를 좀 더 편하게 생각하기 위해 101*101의 크기의 ==Matrix==에서 고민해보기로 했다.
 또한 1의 문제를 좀 더 쉽게 생각하기 위해 각각의 지점에 대한 x좌표 및 y좌표를 list에 넣어 계산하기로 하였다.

###1. 드래콘 커브 생성

드래곤 커브는 마지막 점을 기준으로 각각의 점을 시계방향으로 90도 회전하여 생기는 점과의 연결점으로 정의를 한다. 즉, 아래와 같이 생각할 수 있다.
![image](https://user-images.githubusercontent.com/20368859/40583217-d0c79a3a-61c4-11e8-90b1-2cfc9b9e6b1d.png)
즉, 이를 코드로 표현하면 아래와 같이 표현이 가능하다.
```
void Set(int index, int num){
	int i,j,preX,preY,nd;
	int tIndex = index;
	if(ng == g) return;
	for(i=index-1;i>=0;i--){
			preX = xlist[i+1] - xlist[i];
			preY = ylist[i+1] - ylist[i];
			for(j=0;j<4;j++){
				if(preY == Y[j] && preX == X[j]){
					nd = j;
					break;
				}
			}
			tIndex++;
			xlist[tIndex] = xlist[tIndex-1]+X[(nd+1)%4];
			ylist[tIndex] = ylist[tIndex-1]+Y[(nd+1)%4];
			if((xlist[tIndex]>=0 && xlist[tIndex]<=100) && (ylist[tIndex]>=0 && ylist[tIndex]<=100)){
				space[ylist[tIndex]][xlist[tIndex]] = num;
			}
	}
	ng++;
	Set(tIndex,num);
}
```
1. 드래곤 커브에 해당하는 점들은 Matrix에 표시를 해둔다.
2. 끝점을 초기점으로 하여 끝점 전의 점과의 방향을 알아내어 90도 회전시킨 값을 마지막 점에 더한다.
3. 2번의 계산을 0세대의 마지막 점이 될때까지 반복한다.

###2. 1x1인 정사각형포함 여부 확인
정사각형포함의 여부는 101x101크기의 Matrix를 완전탐색으로 돌면서 확인해주면 된다.
```
int cnt = 0;
for(i=0;i<100;i++){
	for(j=0;j<100;j++){
		if(space[i][j] != 0 && space[i+1][j] != 0 && space[i][j+1] != 0 && space[i+1][j+1] != 0)
			cnt++;
	}
}
```