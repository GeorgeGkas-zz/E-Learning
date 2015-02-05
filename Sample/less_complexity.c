#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(ProfitA,ProfitB,ProfitC) ProfitA > (ProfitB > ProfitC ? ProfitB : ProfitC) ? ProfitA : (ProfitB > ProfitC ? ProfitB : ProfitC)

int sum_array(int* array,int start, int end)
{
    int i = start;
    int res = 0;
   while (i != end) {
       res += array[i];
       i++;
   }
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
    int Permutations = (1 + 0.5*N*(N-3));
    printf("\n\tNumber of Permutations need : %d \n", Permutations);
      puts("\t--------------------------------");
      
    for (int A = 1; A < N - 2; A++) {
        int ProfitA = sum_array(array,0, A - 1);
        int ProfitB = array[A];
        int ProfitC = sum_array(array,A+1, N - 1);
        for (int B = 1; B < N - 1; B++) {
                //here the values are "current" - valid
                int Min = min(ProfitA,ProfitB,ProfitC);

                if( Min < bestMin ) {
                bestA = A, bestB = B, bestMin = Min;
                }
                
                //and here they are being prepared for the next iteration
                ProfitB = ProfitB + array[A+B-1];
                ProfitC = ProfitC - array[A+B];
        }
}
    printf("\n\tThe optimal best solution is %d\n", bestMin);
    free(array);
    return 0;
}
