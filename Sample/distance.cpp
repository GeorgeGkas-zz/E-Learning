#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	
	float max = 0, bestMax = -10000;
	int N = 0;
	
	cin >> N;
	
	int *xi, *yi;
	
	xi = new int[N];
	yi = new int[N];
	
	for (int i = 0; i < N; ++i) {
	    cin >> xi[i] >> yi[i];
	}
	
	for (int i = 0; i < N ; ++i) {
	    for (int j = 0; j < N; ++j) {
	        
	        float dis = sqrt((xi[i] - xi[j])*(xi[i] - xi[j]) + (yi[i] - yi[j])*(yi[i] - yi[j]));
	       
	        abs(dis);
	        max = dis;
	        
	        if ( max > bestMax ) {
	            bestMax = max;
	        }
	    }
	}

	printf("%f\n", bestMax);
	return 0;
}
