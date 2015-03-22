/* Find the max number from input using recursive way algorithm
 */
#include <iostream>
using namespace std;

int maxelem(int N,int i, int best) {
	if (N == 0) return best; // check if we run out of numbers to enter

	cin >> i; // pass the element in current state
	if ( i > best) { // check for max
	best = i;
	}

	maxelem(--N,i, best); // decrease the N by one.
}

int main() {
	int N = 0; // assume that we know the number of elements
	cin >> N;
	cout << "Max number: " << maxelem(N,0, 0) << endl;
	return 0;
}
