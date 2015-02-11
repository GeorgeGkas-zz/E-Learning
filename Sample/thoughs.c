#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(ProfitA,ProfitB,ProfitC) ProfitA > (ProfitB > ProfitC ? ProfitB : ProfitC) ? ProfitA : (ProfitB > ProfitC ? ProfitB : ProfitC)
 
int main()
{
    FILE* input = fopen("share.in","r");
 
    int N = 0;
    fscanf(input,"%d",&N);
 
    int *array = (int*)malloc(N * sizeof(int));
    int sum = 0;

    for (int i = 0; i < N; i++) {
        fscanf(input,"%d",&array[i]);
	sum += array[i];
    }
 
    fclose(input);
 
	int MO = (sum / 3) + 1;
	printf("%d\n",MO);	

        int bestMin = INT_MAX;
	int ProfitA, ProfitB, ProfitC;
	int i = 0;   

	for(i; ProfitA <= MO; i++) {
	 ProfitA += array[i];	
	}

	for(i; ProfitB <= MO; i++) {
	 ProfitB += array[i];	
	}	
	 
	for(i; i < N -1 ; i++) {
	 ProfitC += array[i];	
	}
 
	 bestMin = min(ProfitA,ProfitB,ProfitC);
   
    printf("%d\n", bestMin);
    free(array);
    return 0;
}
