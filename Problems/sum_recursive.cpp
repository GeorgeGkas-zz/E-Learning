/* Return sum all numbers divided by 3 and 5 using recursive way algorithm
 */
#include <iostream>
using namespace std;

int RecursiveSum(int i, int sum) {
	if (i == 1000) return sum;

	if ((i % 3 == 0) || (i % 5 == 0)) {
		sum += i;
	}

	RecursiveSum(++i, sum);
}

int main() {
	cout << "Sum is: " << RecursiveSum(0, 0) << endl;
	return 0;
}
