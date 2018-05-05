#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, begin = 0;
	while(scanf("%d", &N) == 1){
		if(begin){
			printf("\n");
		}
		// Maps person to a pair of Spendings and Earnings
		unordered_map<string, pair<int, int>> pse;
		vector<string> names;
		for(int i=0; i<N; i++){
			string name;
			cin >> name;
			names.push_back(name);
			pse.insert(pair<string, pair<int, int>>(name, pair<int, int>(0, 0)));
		}

		for(int i = 0; i < N; ++i){
			string name;
			int qtdPerson = 0, spent = 0;
			
			cin >> name >> spent >> qtdPerson;
			int partOfMoney = 0;
			if(qtdPerson != 0)
				partOfMoney = spent / qtdPerson;

			spent -= spent - (partOfMoney * qtdPerson);

			pse[name].first = spent;
			for(int j = 0; j < qtdPerson; ++j){
				cin >> name;
				pse[name].second += partOfMoney;
			}
		}
		
		for (int i = 0; i < names.size(); ++i){
			cout << names[i] << " " << (pse[names[i]].second-pse[names[i]].first) << endl;
		}
		begin = 1;
	}

	return 0;
}