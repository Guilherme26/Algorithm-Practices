#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define BLACK 0
#define GRAY -1

int visited[100000];
typedef struct{
	vector<int> adjs;
} Vertex;
Vertex graph[100000];

int DFS(int curIndex){
	if(visited[curIndex] == GRAY)
		return true;
	visited[curIndex] = GRAY;
	for(int i = 0; i < graph[curIndex].adjs.size(); ++i){
		if(visited[graph[curIndex].adjs[i]] == WHITE and DFS(graph[curIndex].adjs[i]))
			return true;
		else if(visited[graph[curIndex].adjs[i]] == GRAY)
			return true;
	}
	visited[curIndex] = BLACK;
	return false;
}

int main(){
	int t,n,m,c1,c2;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		for(int i = 0; i <= 10010; ++i){
			graph[i].adjs.clear();
			visited[i] = WHITE;
		}

		for(int i = 0; i < m; ++i){
			cin >> c1 >> c2;
			graph[c1].adjs.push_back(c2);
		}

		bool cicle = false;
		for(int i = 1; i <= n; ++i){
			if(DFS(i)){
				cicle = true;
				break;
			}
		}

		if(cicle)
			printf("SIM\n");
		else
			printf("NAO\n");
	}

	return 0;
}