#include <bits/stdc++.h>

using namespace std;

typedef long long int lii;
map<lii,lii> votes;

int main(){
	int n, tmp;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> tmp;
		if(votes.find(tmp) != votes.end())
			votes[tmp] += 1;
		else
			votes[tmp] = 1;
	}

	int max = 0;
	for(auto &it : votes)
		max = (it.second > votes[max]) ? it.first : max;
	printf("%d\n", max);
	
	return 0;
}