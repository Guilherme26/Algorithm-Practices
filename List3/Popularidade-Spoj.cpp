#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v;
	while(cin >> n and n){
		map<int,int> ans;
		for(int i = 1; i <= n; ++i)
			ans[i] = 0;

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				cin >> v;
				if(!v)
					continue;
				else
					ans[j] += 1;
			}
		}

		int max = 1;
		for(int i = 2; i <= n; ++i){
			if(ans[max] < ans[i])
				max = i;
		}

		printf("%d\n", ans[max]);
	}

	return 0;
}