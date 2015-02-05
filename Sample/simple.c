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
    
    int Min = 0;
    int bestA = 0, bestB = 0, bestMin = INT_MAX;
    int A, B;
    int i;

    for ( A = 0; A < N - 2; ++A)
    {
        for ( B = A + 1; B < N - 1; ++B)
        {
            int ProfitA = sum_array(array, A + 1);
            int ProfitB = sum_array(array + A + 1, B - A );
            int ProfitC = sum_array(array + B + 1, N - 1 - B );

            //here the values are "current" - valid
            int Min = min(ProfitA,ProfitB,ProfitC);

            if( Min < bestMin ) {
                bestA = A, bestB = B, bestMin = Min;
            }

        }
    }
    printf("\n\tThe optimal best solution is %d\n", bestMin);
    free(array);
    return 0;
}
