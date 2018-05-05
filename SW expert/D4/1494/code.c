#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Min(a,b) a<b?a:b
#define Abs(a) a>0?a:-1*a
#define Max_long 9223372036854775807

typedef struct point{
	long long x;
	long long y;
}Point;


void solve(int index,Point* list,long long x, long long y,int plus,int minus,long long* min,int N);
int main(void){
	char tmp[100];
	int cnt,T,i,index;
	int plus,minus,N;
	long long *result;
	Point list[30];
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","wb");
	fscanf(fin,"%d",&T);
	result = (long long*)malloc(sizeof(long long));
	cnt = 1;
	while(T--){
		index = 0;
		fscanf(fin,"%d",&N);
		*result = Max_long;
		memset(tmp,0,sizeof(char)*100);
		for(i=0;i<N;i++){
			fscanf(fin,"%lld",&list[i].x);
			fscanf(fin,"%lld",&list[i].y);
			
		}
		plus =minus = N/2;
		solve(index,list,0,0,plus,minus,result,N);
		sprintf(tmp,"#%d %lld\n",cnt++,*result);
		printf("%s\n",tmp);
		fwrite(tmp,sizeof(char),strlen(tmp),fout);	
	}
	fclose(fin);
	fclose(fout);
}
void solve(int index,Point* list,long long x, long long y,int plus,int minus,long long* min,int N){
	if(index==N){
		long long tmp = x*x+y*y;
		*min = Min(tmp,*min);
		return;
	}
	if(plus !=0){
		solve(index+1,list,x+list[index].x,y+list[index].y,plus-1,minus,min,N);
	}
	if(minus !=0){
		solve(index+1,list,x-list[index].x,y-list[index].y,plus,minus-1,min,N);
	}
}