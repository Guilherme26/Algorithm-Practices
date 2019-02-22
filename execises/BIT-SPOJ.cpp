#include <bits/stdc++.h>

using namespace std;

int values[] = {0,1,5,10,50}, v[5][10005];

int main(){
	int c, count=1;
	while(scanf("%d", &c) and c){
		int sol[] = {0,0,0,0,0};

		for (int i = 0; i <= 4; ++i)
			for (int j = 0; j <= c; ++j)
				v[i][j] = SHRT_MAX;

		for (int i = 1; i <= 4; ++i){
			for (int j = 0; j <= c; ++j){
				if(j%values[i]==0)
					v[i][j] = j/values[i];
				if(j-values[i]>=0)
					v[i][j] = min(v[i-1][j], v[i][j-values[i]]+1);

				v[i][j] = min(v[i-1][j], v[i][j]);
			}
		}

		// Finds the solution
		int i = 4, j = c;
		while(j){
			if(j-values[i] >= 0 and v[i][j] == v[i][j-values[i]]+1){
				sol[i] += 1;
				j = j-values[i];
			} 
			else
				i = i-1;

			if(v[i][j] == v[i-1][j])
				i = i-1;
		}

		printf("Teste %d\n", count);
		printf("%d %d %d %d\n\n", sol[4], sol[3], sol[2], sol[1]);
		count += 1;
	}


	return 0;
}