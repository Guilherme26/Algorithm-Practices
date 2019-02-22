#include <bits/stdc++.h>

using namespace std;

long long int g[10000][10000];

void shortestPath(int nVertices){
	for(int k = 0; k < nVertices; ++k){
		for(int i = 0; i < nVertices; ++i){
			for(int j = 0; j < nVertices; ++j){
				g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
			}
		}
	}
}

int main(){
	int crossings, streets, queries, cont = 1;
	while(cin >> crossings >> streets >> queries and crossings and streets and queries){
		if(cont > 1)
			printf("\n");
		for(int i = 0; i < crossings; ++i){
			for(int j = 0; j < crossings; ++j){
				g[i][j] = INT_MAX;
			}
			g[i][i] = 0;
		}

		int c1, c2, d;
		for(int i = 0; i < streets; ++i){
			cin >> c1 >> c2 >> d;
			c1--, c2--;
			g[c1][c2] = d;
			g[c2][c1] = d;
		}
		

		shortestPath(crossings);

		printf("Case #%d\n", cont);
		for(int i = 0; i < queries; ++i){
			cin >> c1 >> c2;
			c1--, c2--;
			if(g[c1][c2] < INT_MAX)
				printf("%lld\n", g[c1][c2]);
			else
				printf("no path\n");
		}
		cont += 1;
	}

	return 0;
}