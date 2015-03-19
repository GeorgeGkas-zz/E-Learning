#include <iostream>
#include <fstream>

using namespace std;

struct complex {
	int city;
	int road;
};

int main() {
	int cities = 0, roads = 0;
	int origin = 0, destin = 0;

	ifstream input;
	ofstream output;
	input.open("xxx.in");
	output.open("xxx.out");

	input >> cities >> roads;
	cout << endl << "Cities: " << cities << endl << "Roads: " << roads << endl; 


	struct complex matrix[cities];
	
	for (int i = 0; i < roads; ++i) {
		input >> matrix[i].city >> matrix[i].road;
	}

	for (int i = 0; i < roads; ++i) {
		cout <<  matrix[i].city << " " << matrix[i].road << endl;
	}
	cout << endl;

	input >> origin >> destin;
	cout << "Start: " << origin << " End: " << destin << endl;


	if (roads == 0) {
		output << 0;
		return 0;
	}

	

}
