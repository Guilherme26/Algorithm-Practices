#include <bits/stdc++.h>

using namespace std;

typedef pair<string,int> psi;

bool compare_(const psi &p1, const psi &p2){
	if(p1.second == p2.second and p1.first.compare(p2.first) > 0)
		return true;
	if(p1.second < p2.second)
		return true;
	else 
		return false;
}

int main(){
	int n, grade, inst = 1, begin = 1;
	string s;

	while(cin >> n){
		vector< psi > ans;
		if(!begin)
			printf("\n");

		for(int i = 0; i < n; ++i){
			cin >> s >> grade;
			ans.push_back(make_pair(s, grade));
		}

		sort(ans.begin(), ans.end(), compare_);
		printf("Instancia %d\n%s\n", inst, ans[0].first.c_str());
		inst += 1;
		begin = 0;
	}

	return 0;
}