#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, dim, t, s=42195;
	scanf("%d %d", &n, &dim);

	vector<int> v;
	for(int i = 0; i < n; ++i){
		scanf("%d", &t);
		v.push_back(t);
	}

	for(int i = 1; i < n; ++i){
		if(v[i]-v[i-1] > dim){
			printf("N\n");
			return 0;
		}
	}

	if(dim>= s-v[n-1])
		printf("S\n");
	else
		printf("N\n");

	return 0;
}