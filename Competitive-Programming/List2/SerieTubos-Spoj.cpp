#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define BLACK 0

typedef pair<int,int> pii;
typedef struct{
	vector<pii> adjs;
} Vertex;

int color[1010];
Vertex g[1010];
map< pair<int,int>, int> mapping;
int flag, n;

void DFS(int index){
	color[index] = BLACK;

	if(g[index].adjs.size() == 1 and (index != n or index != 1))
		flag = false;

	for(int i = 0; i < g[index].adjs.size(); ++i){
		int curIndex = g[index].adjs[i].second;
		if(color[curIndex] and mapping[g[index].adjs[i]] == 1){
			pii p(g[index].adjs[i].second, g[index].adjs[i].first);
			mapping[p] = 0;
			
			DFS(curIndex);
		}
	}
}

int main(){
	int m;
	while(cin >> n >> m and n){
		for(int i = 0; i < 1010; ++i){
			color[i] = WHITE;
			g[i].adjs.clear();
			mapping.clear();
		}

		int a, b;
		for(int i = 0; i < m; ++i){
			cin >> a >> b;

			pii p1(a,b), p2(b,a);
			mapping.insert(pair<pii, int>(p1, 1));
			mapping.insert(pair<pii, int>(p2, 1));

			g[a].adjs.push_back(p1);
			g[b].adjs.push_back(p2);
		}

		flag = true;
		int countCalls = 0;
		for(int i = 1; i <= n; ++i){
			if(color[i]){
				DFS(i);
				countCalls += 1;
			}
			if(countCalls >= 2)
				break;
		}

		if(countCalls >= 2 or flag == false){
			printf("N\n");
			continue;
		}

		for(int i = 0; i <= n; ++i)
			color[i] = WHITE;

		flag = true;
		countCalls = 0;
		for(int i = n; i > 0; i--){
			if(color[i]){
				DFS(i);
				countCalls += 1;
			}
			if(countCalls >= 2)
				break;
		}

		if(countCalls >= 2 or flag == false)
			printf("N\n");
		else
			printf("S\n");
	}


	return 0;
}