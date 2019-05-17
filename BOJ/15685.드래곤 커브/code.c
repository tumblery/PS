#include<stdio.h>
#include<malloc.h>

int space[101][101] = {0,};
int X[4] = {1,0,-1,0};
int Y[4] = {0,-1,0,1};
int g,ng;
int xlist[1100],ylist[1100];
void Set(int index, int num);
int main(void){
	int x,y,d;
	int N,i,j,k,l;

	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d %d %d",&x,&y,&d,&g);
		xlist[0] = x;
		ylist[0] = y;
		if((x>=0 && x<=100) && (y>=0 && y<=100))
			space[y][x] = i+1;

		x = x + X[d];
		y = y + Y[d];

		xlist[1] = x;
		ylist[1] = y;

		if((x>=0 && x<=100) && (y>=0 && y<=100))
			space[y][x] = i+1;
		ng = 0;
		Set(1,i+1);
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%d ",space[i][j]);
		}
		printf("\n");
	}
	int cnt = 0;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(space[i][j] != 0 && space[i+1][j] != 0 && space[i][j+1] != 0 && space[i+1][j+1] != 0)
				cnt++;
		}
	}

	printf("%d",cnt);
	return 0;
}

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