#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max(a,b) a>b?a:b

int solve(int N,int* list);
int main(void){
	int list[1000];
	char tmp[100];
	int N,i,j,ans;
	
	
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","wb");

	for(i=0;i<10;i++){
		fscanf(fin,"%d",&N);
		printf("%d ",N);
		memset(list,0,1000*sizeof(int));
		for(j=0;j<N;j++){
			fscanf(fin,"%d",&list[j]);
			printf("%d ",list[j]);
		}
		printf("%d\n",list[1]);
		ans = solve(N,list);
		printf("\n");
		sprintf(tmp,"#%d %d\n",i+1,ans);
		fwrite(tmp,sizeof(char),strlen(tmp),fout);
		
	}
	
	fclose(fin);
	fclose(fout);
}
int solve(int N,int* list){
	int i,Lmax,Rmax,max;
	int res = 0;
//	printf("list: %d\n",list[0]);
	for(i=2;i<N-2;i++){
		Lmax = Max(list[i-2],list[i-1]);
		Rmax = Max(list[i+1],list[i+2]);
		max = Max(Lmax,Rmax);
//		printf("%d",max);
		if(list[i]>max){
			res += (list[i]-max);
		}
	}
	return res;
}