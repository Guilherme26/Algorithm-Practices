#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, num, begin = 1;

	while(scanf("%d", &n) and n){
		if(!begin)
			printf("\n");
		vector<int> v;
		for(int i = 0; i < n; ++i){
			scanf("%d", &num);
			v.push_back(num);
		}

		sort(v.begin(), v.end());
		do{
			for(int i = 0; i < n; ++i){
				if(i)
					printf(" ");
				printf("%d", v[i]);
			}
			printf("\n");
		}while(next_permutation(v.begin(), v.end()));
		begin = false;
	}

	return 0;
}