/*
Based in SPOJ Problem Set (tutorial)
21591. Cumulative Sum Query
Problem code: CSUMQ
*/

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
    
    for (int i = 0; i < N; i++) {
        fscanf(input,"%d",&array[i]);
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
    for ( int i = 0; i < Q ; i++) {
        int first = querrie[i].first;
        int last = querrie[i].last;
		
        sum = sum_array(array,first,last);
		
        printf("Number of querry : %d , sum is %d\n",i ,sum);
    }
	
    free(array); 
    return 0;
}

