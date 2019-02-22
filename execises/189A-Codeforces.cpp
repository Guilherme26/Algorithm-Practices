#include <bits/stdc++.h>

using namespace std;

int main(){
	int m[4][4001], n, v[4];

	for(int i = 0; i < 4; ++i) for(int j = 0; j < 4001; ++j) m[i][j]=0;
	cin >> n >> v[1] >> v[2] >> v[3];

	for(int i = 1; i < 4; ++i){
		int min_index=i, aux;
		for(int j = i; j < 4; ++j){
			if(v[min_index] > v[j])
				min_index = j;
		}

		aux = v[i];
		v[i] = v[min_index];
		v[min_index] = aux;
	}	

	int line=0;
	for(int i = 1; i < 4; ++i){

		if(v[i] > n)
			break;

		line=i;
		for(int j = 1; j <= n; ++j){
			if(j%v[i] && m[i-1][j%v[i]])
				m[i][j] = j/v[i]+m[i-1][j%v[i]];
			else if(j%v[i] == 0)
				m[i][j] = j/v[i];

			if(j>=v[i] && m[i][j-v[i]])
				m[i][j] = max(m[i][j], m[i][j-v[i]]+1);

			m[i][j] = max(m[i][j], m[i-1][j]);
		}

		if(m[i][n] || m[i-1][n-v[i]])
			m[i][n] = max(m[i][n], m[i-1][n-v[i]]+1);
	}

	printf("%d\n",m[line][n]);

	return 0;
}