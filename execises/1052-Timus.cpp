#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
	int n, x, y;
	vector<pii> c;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x >> y;
		c.push_back(make_pair(x,y));
	}

	sort(c.begin(), c.end());

	int max = 0;
	for(int i = 0; i < n; ++i){
		map<long long int, int> m;
		for(int j = 0; j < n; ++j){
			if(i!=j){
				long long int CA = (1.0*(c[i].second-c[j].second)/(c[i].first-c[j].first))*1000000000;
				if(m.find(CA) != m.end())
					m[CA] += 1;
				else
					m[CA] = 1;
			}
		}

		for(map<long long int,int>::iterator it = m.begin(); it != m.end(); it++)
			if(max < it->second)	max = it->second;
	}

	printf("%d\n", max+1);

	return 0;
}