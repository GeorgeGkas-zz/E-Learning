#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAX_N = 1000;

int main() {
	
	float max = 0, bestMax = -10000;
	int N = 0;
	
	cin >> N;
	
	int xi[MAX_N], yi[MAX_N];
	
	for (int i = 0; i < N; ++i) {
	    cin >> xi[i] >> yi[i];
	}
	
	for (int i = 0; i < N ; ++i) {
	    for (int j = 0; j < N; ++j) {
	        
	        float dis = sqrt((xi[i] - xi[j])*(xi[i] - xi[j]) + (yi[i] - yi[j])*(yi[i] - yi[j]));
	       
	        dis =  abs(dis);
	        max = dis;
	        
	        if ( max > bestMax ) {
	            bestMax = max;
	        }
	    }
	}

	printf("%f\n", bestMax);
	return 0;
}
