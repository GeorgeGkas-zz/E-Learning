/* Πίνακας γειτνίασεις
 * Με το παρακάτω τρόπο μπορούμε να χρεισημοποιήσουμε bfs & dfs search!
 */

#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int N, Start, End;
int visited[1000];
int matrix[1000][1000];

int DFS(int i) {
    int j;
    visited[i] = 1;

    for(j=0;j<N;j++) {
    	if( !visited[j] && matrix[i][j] == 1) {
    		DFS(j);
    	}
    	++Start;
    }

    if( Start == End) {
    	return 's';
    }
    else {
    	return 'f';
    }
}

int main() {

	// Read the number of cities into the matrix
	ifstream input;

	input.open("xxx.in");

	input >> N; // cities

	for (int i =0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			 matrix[i][j] = 0;
		}
	}

	int M = 0; // roads
	input >> M;

	// pass the city points. Set 1 to connect with road
	for (int i = 0; i < M; ++i) {
		int s = 0, t = 0;
		input >> s >> t;
		matrix[s][t] = 1;
	}

	input >> Start >> End; // start and end city we want to travel

	input.close();

	// starting dfs procedure. We want to find if we can go from city Start to city End
	// Set all visit to zero
	for (int i = 0; i < N; ++i) {
		visited[i] = 0;
	}

	char result =  DFS(0); // return s for succeed and f for false

	printf("\n%c\n", result);

}
