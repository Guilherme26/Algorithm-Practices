#include <bits/stdc++.h>

using namespace std;

#define l v[i].length
#define s v[i].sorries

typedef struct phrase{
	int length;
	int sorries;

	bool operator<(const phrase p) const{
		if(length > p.length)
			return false;

		if(length == p.length and sorries >= p.sorries)
			return false;

		return true;
	}
} phrase;

int main(){
	int count = 1;

	while(1){
		int sol[55][1005], length, n;
		vector<phrase> v;
		phrase t;

		scanf("%d %d", &length, &n);
		if(length == n and n == 0)
			break;

		for(int i = 0; i <= n; ++i) for(int j = 0; j <= length; ++j) sol[i][j] = 0;

		// Leaves 0th position unused
		v.push_back(t);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &t.length, &t.sorries);
			v.push_back(t);
		}
		sort(v.begin()+1, v.end());

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= length; ++j){
				if(l <= j)
					sol[i][j] = max(sol[i-1][j-l]+s, sol[i-1][j]);
				else
					sol[i][j] = sol[i-1][j];
			}
		}

		printf("Teste %d\n", count);
		printf("%d\n", sol[n][length]);
		printf("\n");
		count += 1;
	}

	return 0;
}