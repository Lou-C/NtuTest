#include<stdio.h>

long long int M, N;
long long int SUM[2];

int main(){
	
	long long int MIN_S, MAX_S, re;
	int len[100000];
	
	int i, j, m;
	
	M = 90000;   N = 100000;  
	SUM[0] = 87127231192;
	SUM[1] = 5994891682;
	
	
	MIN_S = N*1 + (1 + M)*M/2 - 1;
	MAX_S = N*M + (1 + M)*M/2 - M;
	
	for(i = 0; i<2; i++){
		if(SUM[i] > MAX_S || SUM[i] < MIN_S){
			printf("%lld: No answers.\n",SUM[i]);
			SUM[i] = 0; 
		}
	}
	
	m = M;
	for(i = 0; i<2; i++){
		if(SUM[i] != 0){
			re = SUM[i] - MIN_S;
			len[0] = N-1;
			
			while (re != 0){
				// m = m-1;
				len[m-1] = re / (m-1);
				if(len[m-1])
					len[0] -= 1;
				re = re % (m - 1);
				m = m - 1;
			}
			
			printf("%lld ",SUM[i]);
			
			for(m = 0; m <= M-1 ; m++){
				if(len[m] != 0){
					for (j = len[m]; j>0; j--)
						printf("R");
				}
				if(m<M-1)
					printf("D");  
			}
			
			printf("\n");
			SUM[i] = 0;
		}
		
	}

	return 0;
	
}
