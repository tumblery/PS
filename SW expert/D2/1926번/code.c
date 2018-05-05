#include<stdio.h>
#include<string.h>
int check(int N);
int main(void){
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","wb");

	int N,i,tmp,j;
	char buf[1024],t[1024];

	fscanf(fin,"%d",&N);
	printf("%d\n",N);
	memset(buf,0,1024);
	for(i=1;i<=N;i++){
		tmp = check(i);
		if(tmp == 0){
			sprintf(t,"%d",i);
			strcat(buf,t);
		}else{
			for(j=0;j<tmp;j++)
				strcat(buf,"-");
		}
		strcat(buf," ");
	}
	fwrite(buf,sizeof(char),strlen(buf),fout);

	fclose(fin);
	fclose(fout);
}

int check(int N){
	int tmp;
	int res = 0;
	while(N != 0){
		tmp = N%10;
		if(tmp%3 == 0 && tmp != 0){
			res++;
		}
		N = N/10;
	}

	return res;
}