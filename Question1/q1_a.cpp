#include<stdio.h>

int M, N;
char ans[100];

void dsp(int m , int n , int sum, int pos, int SUM){
	
	if (n == N && m == M){
		
		if (sum == SUM){
			printf("%d ",sum);
			puts(ans);     // output one answer
		}
		
		return;
	}
	
	if (m < M){
		ans[pos] = 'D';
		dsp(m+1,n,sum+m+1,pos+1,SUM);
		ans[pos] = '\0';
	}
	
	if (n < N){
		ans[pos] = 'R';
		dsp(m,n+1,sum+m,pos+1,SUM);
		ans[pos] = '\0';
	}

}
	


int main(){
	
	int i;
	int ALL_SUM[4] =  {65,72,90,110};
	M = 9;   
	N = 9;
	
	for(i = 0; i < 4; i++){
		dsp(1,1,1,0,ALL_SUM[i]);
		printf("\n");
	}
	

}
