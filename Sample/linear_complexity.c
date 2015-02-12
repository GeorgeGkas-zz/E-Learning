#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int first;
	int last;
};

int sum_array(int *array, int first, int last) {
    int sum = 0;
    for (int i = first; i <= last; i++) {
        sum += array[i];
    }
	
    return sum;
}

int main() {
    FILE* input = fopen("share.in","r");
    
    int N = 0;
    fscanf(input,"%d",&N);
    
    int *array = (int*)malloc(N * sizeof(int));
    int *integralArray = (int*)malloc(N * sizeof(int));    

    for (int i = 0; i < N; i++) {
        fscanf(input,"%d",&array[i]);

        /************************************************************************************/
        /*the element at integralArray[i] is the sum of all elements in array from 0 to i. 
        to get the sum from first to last, where last > first, integralArray[first] is the sum from 0 to first 
        and integralArray[last] is the sum from 0 to last so we can just compute 
        integralArray[last] - integralArray[first] 
        to get the total from first to last. Intuitively, integralArray[first] includes 
        the numbers we want but it also includes the numbers up to and including first. We don't want 
        those so we take them off again. */
        /************************************************************************************/
        integralArray[i] = array[i] + ((i > 0) ? array[i-1] : 0);
    }
	
    int Q = 0;
    fscanf(input,"%d",&Q);

    struct node querrie[Q];
    
    for (int i=0; i < Q; i++) {
        fscanf(input,"%d",&querrie[i].first); 
        fscanf(input,"%d",&querrie[i].last); 
    }
	
    fclose(input);
    
    int sum = 0;
    for (int i = 0; i < Q ; i++) {
        int first = querrie[i].first;
        int last = querrie[i].last;
		
        sum = integralArray[last] - ((first > 0) ? array[first-1] : 0);
		
        printf("Number of querry : %d , sum is %d\n",i ,sum);
    }
	
    free(array); 
    return 0;
}
