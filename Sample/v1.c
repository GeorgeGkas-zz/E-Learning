#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(ProfitA, ProfitB, ProfitC) ProfitA > (ProfitB > ProfitC ? ProfitB : ProfitC) ? ProfitA : (ProfitB > ProfitC ? ProfitB : ProfitC)
#define IOERROR 5   // 'Input/Output Error'


size_t PassProfit(FILE *input, size_t *wage, const int N) {  
    for (size_t i = 0; i < N; i++) {
        fscanf(input, "%d", &wage[i]); 
    }

    return *wage;
}

size_t SumArray(size_t *wage, int start, const int end) { 
    long sum = 0;    
    while (start != end) {
        sum += wage[start];
        start++;
	}
    return sum;
}

size_t ProcessArray(size_t *array, size_t N) {
    long current = 0; 
    long bestMin = LONG_MAX; 
    long ProfitA = 0, ProfitB = 0, ProfitC = 0; 
        
    long *pA, *pB, *pC;
    pA = pB = pC = &array[0];
    
 	ProfitC = SumArray(array, 2, N); 

    for (size_t A = 0; A < N - 2; ++A) {
        ProfitA += *(pA + A); 

        for (size_t B = A + 1; B < N - 1; ++B) {
            ProfitB += *(pB + B); 
                       
            current = min(ProfitA, ProfitB, ProfitC); 

            if (current < bestMin) {
                bestMin = current;
            }
              
            ProfitC -= *(pC + B + 1); 
        }

    ProfitB = 0; 
    ProfitC = SumArray(array, A + 3, N); 
    } 

    return bestMin;
}
 
FILE *ReadInput(const char *filename_r) {  
    FILE *input = fopen(filename_r, "r");  
  
    if (input == NULL) {
        exit(IOERROR);  
    }

    return input;  
}  

void WriteOutput(const int total, const char *filename_w) {  
    FILE *output = fopen(filename_w, "w");  
  
    if(output == NULL) { 
        exit(IOERROR);   
    }

    fprintf(output, "%d\n", total);  
    fclose(output);  
}

size_t CountDays(FILE *input) {  
    int days = 0;  
    fscanf(input, "%i", &days);  
    return days;  
}  

int main() {
    const char *filename_r = "share.in"; 
    const char *filename_w = "share.out"; 

    FILE *input = ReadInput(filename_r); 
    
    size_t N = CountDays(input);

    size_t *wage = malloc(N * sizeof *wage);
    if (wage==NULL) {  
    exit(1); 
    }

    PassProfit(input, wage, N);
    fclose(input);    
    
    size_t bestMin = ProcessArray(wage, N); 

    free(wage);

    WriteOutput(bestMin, filename_w); 

    return 0;
}
