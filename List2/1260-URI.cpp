#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, begin = 1;

	scanf("%d", &n);
	while(n--){
		int count = 0;
		map<string, int> ans;

		if(!begin)
			printf("\n");
		
		scanf("\n");
		string line;
		while(getline(cin, line) and line != ""){
			if(ans.find(line) != ans.end())
				ans[line] += 1;
			else
				ans[line] = 1;
			count += 1;
		}

		for(auto &it : ans)
			printf("%s %.4f\n", it.first.c_str(), it.second*(100.0/count));
		begin = 0;
	}
	
	return 0;
}