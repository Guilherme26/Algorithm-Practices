#include <bits/stdc++.h>

using namespace std;

int M[1010][1010], P, N;

pair<int, int> checkLine(int line, int column, int C){
	int count = 0;

	if(column+C-1>N)
		return make_pair(column, 0);

	int i;
	for (i = 0; column+i <= N; ++i){
		if(M[line][column+i] == 1)
			count += 1;
		else
			break;
	}
	return make_pair(column+i, count);
}

int main(){
	for(int i = 0; i < 1010; ++i)
		for(int j = 0; j < 1010; ++j)
			M[i][j] = 0;

	int C;
	while(cin >> P >> N >> C and P and N and C){
		for(int i = 1; i <= N; ++i)
			for (int j = 1; j <= P; ++j)
				scanf("%d", &M[j][i]);

		int count = 0;
		for (int line = 1; line <= P; ++line){
			for (int column = 1; column <= N; ++column){
				pair<int, int> r = checkLine(line, column, C);
				if(r.second >= C)
					count += 1;
				column = r.first;
			}
		}
		printf("%d\n", count);
	}	

	return 0;
}