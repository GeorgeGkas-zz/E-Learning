#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(ProfitA,ProfitB,ProfitC) ProfitA > (ProfitB > ProfitC ? ProfitB : ProfitC) ? ProfitA : (ProfitB > ProfitC ? ProfitB : ProfitC)
 
int sum_array(int* array, int cnt)
{
    int res = 0;
    int i;
    for ( i = 0; i < cnt ; ++i)
        res += array[i];
    return res;
}
 
int main()
{
    FILE* input = fopen("share.in","r");
 
    int N = 0;
    fscanf(input,"%d",&N);
 
    int *array = (int*)malloc(N * sizeof(int));
 
    for (int i = 0; i < N; i++)
        fscanf(input,"%d",&array[i]);
 
    fclose(input);
 

    int bestMin = INT_MAX;
    int A = 0;
    int B = 1;
    
    for ( A; A < N - 2; ++A)
    {
	
	if (B < N - 1) {
	++B;
	int ProfitA = sum_array(array, A + 1);
        int ProfitB = sum_array(array + A + 1, B - A );
        int ProfitC = sum_array(array + B + 1, N - 1 - B );	
	
	
	 int Min = min(ProfitA,ProfitB,ProfitC);
 
            if( Min < bestMin )
                bestMin = Min;
	
	   
	} else break;


       
    }
    printf("%d\n", bestMin);
    free(array);
    return 0;
}
