#include <bits/stdc++.h>

using namespace std;

long long int M[510][510];

int main(){
	int N, aux;
	vector<int> built_in_order;
	cin >> N;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; ++j)
			M[i][j] = INT_MAX;
		M[i][i] = 0;
	}

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; ++j)
			cin >> M[i][j];

	for(int i = 1; i <= N; ++i){
		cin >> aux;
		built_in_order.push_back(aux);
	}

	vector<long long int> sol;
	for(int k = built_in_order.size()-1; k >= 0; k--){
		long long int sum = 0;
		for(int i = 1; i <= N; ++i)
			for(int j = 1; j <= N; ++j)
				if(M[i][j] > M[i][built_in_order[k]] + M[built_in_order[k]][j])
					M[i][j] = M[i][built_in_order[k]] + M[built_in_order[k]][j];

		for(int i = built_in_order.size()-1; i >= k; i--)
			for(int j = built_in_order.size()-1; j >= k; j--)
				sum += (M[built_in_order[i]][built_in_order[j]] >= INT_MAX) ? 0 : M[built_in_order[i]][built_in_order[j]];

		sol.push_back(sum);
	}

	for(int i = sol.size()-1; i >= 0 ; i--){
		if(i==0)
			printf("%lld", sol[i]);
		else		
			printf("%lld ", sol[i]);
	}
	printf("\n");

	return 0;
}