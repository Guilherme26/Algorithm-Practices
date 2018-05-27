#include <bits/stdc++.h>

using namespace std;

long long int M[510][510];

int main(){
	int N, E, begin = 1;

	while(cin >> N >> E and N){
		for (int i = 0; i < 510; ++i){
			for (int j = 0; j < 510; ++j)
				M[i][j] = INT_MAX;
			M[i][i] = 0;
		}

		int x, y, w, k;
		for (int i = 0; i < E; ++i){
			cin >> x >> y >> w;
			M[x][y] = w;

			if(M[y][x] != INT_MAX)
				M[x][y] = M[y][x] = 0;
		}

		for (int k = 1; k <= N; ++k){
			for (int i = 1; i <= N; ++i){
				for (int j = 1; j <= N; ++j){
					M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
				}
			}
		}


		cin >> k;
		for (int i = 0; i < k; ++i){
			cin >> x >> y;
			if(M[x][y] < INT_MAX)
				printf("%lld\n", M[x][y]);
			else
				printf("Nao e possivel entregar a carta\n");
		}
		
		printf("\n");
	}

	return 0;
}