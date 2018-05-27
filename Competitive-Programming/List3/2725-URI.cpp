#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define BLACK 0
typedef long long int lli;
typedef pair<int,int> pii;
int color[1005];
int n;
int g[1005][1005];

int GCD(int x, int y){
	if(y == 0)
		return x;
	else
		GCD(y, x%y);
}

lli PrimMST(int g[][1005]){
	lli sum = 0;
	priority_queue<pii, vector< pii >, greater< pii > > pq;
	pq.push(make_pair(0, 0));

	while(pq.size()){
		pii p = pq.top();
		pq.pop();

		if(color[p.second] == BLACK)
			continue;
		color[p.second] = BLACK;
		sum += p.first;
		for(int j = 0; j < n; ++j)
			pq.push(make_pair(g[p.second][j], j));
	}

	return sum;
}


int main(){
	int t,k,x,y;
	scanf("%d", &t);

	while(t--){
		vector< pii > v;
		
		scanf("%d %d", &n, &k);

		for(int i = 0; i < n; ++i){
			color[i] = WHITE;
			scanf("%d %d", &x, &y);
			v.push_back(make_pair(x,y));
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				int d = GCD(abs(v[i].first-v[j].first), abs(v[i].second-v[j].second));
				d -= 1;
				g[i][j] = d;
				g[j][i] = d;
			}
			g[i][i] = INT_MAX;
		}
		printf("%lld\n", PrimMST(g)*k);
	}

	return 0;
}