#include <bits/stdc++.h>

using namespace std;

int st[50000];
int ranked[50000];

int find(int i){
	if(st[i] == i)
		return i;
	return find(st[i]);
}

int main(){
	int n, m, caso = 1;
	while(cin >> n >> m and (n and m)){
		int religions = 0, i, j, pessoas = 0;

		for(int k = 0; k < 50000; ++k){
			st[k] = k;
			ranked[k] = 0;
		}

		for(int k = 0; k < m; ++k){
			cin >> i >> j;
			int iSet = find(i), jSet = find(j);
			if(iSet != i)
				st[i] = iSet;
			if(jSet != j)
				st[j] = jSet;
			
			if(iSet != jSet and ranked[jSet] == 0 and ranked[iSet] == 0){
				st[jSet] = iSet;
				religions += 1;
				pessoas += 2;
			}
			else if(iSet != jSet){
				st[jSet] = iSet;
				if(ranked[iSet] and ranked[jSet])
					religions -= 1;
				else 
					pessoas += 1;
			}
			ranked[i] = 1, ranked[j] = 1;
		}

		if(pessoas != n)
			religions +=  abs(n-pessoas);
		printf("Case %d: %d\n", caso, religions);
		caso += 1;
	}

	return 0;
}