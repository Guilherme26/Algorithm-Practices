#include <bits/stdc++.h>

using namespace std;

#define WHITE -1
typedef pair<int,int> pii;
typedef struct{
	vector< pii > adjs;
} Vertex;

int color[110], n, m, c1, c2;
bool deuMerda;
map<pii, map<pii, int> > g;
vector< pii > tmp;

int getIndex(pii initial){
	for(int i = 0; i < m; ++i)
		if(tmp[i] == initial)
			return i;
}

void dfs(pii initial, int state){
	color[getIndex(initial)] = state;
	for(auto& it: g[initial]){
		if(color[getIndex(it.first)] == WHITE)
			dfs(it.first, !state);
		else if(color[getIndex(it.first)] == state){
			deuMerda = true;
			return;
		}
	}
}

int main(){
	cin >> n >> m;

	for(int i = 0; i <= m; ++i) color[i] = WHITE;

	for(int i = 0; i < m; ++i){
		cin >> c1 >> c2;
		if(c1 > c2)
			tmp.push_back(make_pair(c2,c1));
		else
			tmp.push_back(make_pair(c1,c2));
	}

	for(int i = 0; i < m; ++i){
		for(int j = 0; j < m; ++j){
			if((i != j) and (tmp[i].first < tmp[j].first and tmp[i].second > tmp[j].first and tmp[i].second < tmp[j].second
				or tmp[j].first < tmp[i].first and tmp[j].second > tmp[i].first and tmp[j].second < tmp[i].second)){
				pii p1 = make_pair(tmp[i].first, tmp[i].second);
				pii p2 = make_pair(tmp[j].first, tmp[j].second);
				g[p1][p2] = 1;
				g[p2][p1] = 1;
			}
		}
	}

	deuMerda = false;
	for(int i = 0; i < m; ++i){
		if(color[getIndex(tmp[i])] == WHITE){
			dfs(tmp[i], 0);
		}
	}

	if(deuMerda)
		printf("Impossible\n");
	else{
		for(int i = 0; i < m; ++i){
			if(color[i])
				printf("o");
			else
				printf("i");
		}
		printf("\n");
	}

	return 0;
}