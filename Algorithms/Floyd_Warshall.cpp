/*
	Guilherme Resende - 2018
	The code below is Floyd-Warshall algorithm, that calculates the 
	smallest path between any two vertices on a weighted, directed 
	graph without negative cicles (but, where the weights can be negative).
	The algorithm have time complexity of O(N³).
*/

using namespace std;

long long int M[510][510];

void Floyd_Warshall(int N){
	for (int k = 1; k <= N; ++k){
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= N; ++j){
				M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
			}
		}
	}
}
