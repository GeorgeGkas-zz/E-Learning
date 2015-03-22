#include <iostream>

using namespace std;

int A[100000];
int B[100000];
int C[200000];

int RecursiveMerge(int A[], int B[], int C[], int i, int j,int z, int N, int M) {
	if (N == 1 && M == 1) {
		return 's';
	}
	else {
		if (M == 0) {
			C[z] = A[i];
		}
		else {
			if (N == 0) {
				C[z] = B[j];
			}
			else {
				if (A[i] <= B[j]) {
					C[z] = A[i];
					C[z+1] = B[j];
				} 
				else {
					C[z] = B[j];
					C[z+1] = A[i];
				}
			}
		}
	}
	RecursiveMerge(A, B, C, ++i, ++j,++z, --N, --M);
}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}

	char c = RecursiveMerge(A, B, C, 0, 0,0, N, M);
}
