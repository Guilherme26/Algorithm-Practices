#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, d, bi, ci;

	while(cin >> a >> d and a){
		vector<int> attack, defense;
		bool flag = true;

		for(int i = 0; i < a; ++i){
			cin >> bi;
			attack.push_back(bi);
		}
		for(int i = 0; i < d; ++i){
			cin >> ci;
			defense.push_back(ci);
		}

		sort(attack.begin(), attack.end());
		sort(defense.begin(), defense.end());

		if(attack[0] < defense[1])
			printf("Y\n");
		else
			printf("N\n");
	}
	
	return 0;
}