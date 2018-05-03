#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
	int n, count = 1, x1, x2;
	char x;

	while(cin >> n and n){
		int begin = 1;
		vector< vector< pii > > in;
		vector< vector<char> > pass;
		for(int k = 0; k < n; ++k){
			vector< pii > tmp1;
			for(int i = 0; i < 5; ++i){
				cin >> x1 >> x2;
				tmp1.push_back(make_pair(x1,x2));
			}
			in.push_back(tmp1);
			vector<char> tmp2;
			for(int i = 0; i < 6; ++i){
				cin >> x;
				tmp2.push_back(x);
			}
			pass.push_back(tmp2);
		}


		printf("Teste %d\n", count);

		int ans[10];
		for(int i = 0; i < 6; ++i){
			if(!begin)
				printf(" ");
			
			for(int j = 0; j < 10; ++j)
				ans[j] = 0;

			for(int j = 0; j < n; ++j){
				int index = pass[j][i] - 'A';
				ans[in[j][index].first] += 1;
				ans[in[j][index].second] += 1;
			}

			int maxIndex = 0;
			for(int i = 1; i < 10; ++i)
				if(ans[i] > ans[maxIndex])
					maxIndex = i;
			printf("%d", maxIndex);
			begin = 0;
		}
		printf("\n");
		count += 1;
	}

	return 0;
}