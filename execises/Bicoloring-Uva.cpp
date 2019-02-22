#include <bits/stdc++.h>

using namespace std;


#define WHITE 2
#define BLACK 0
#define GREY 1

typedef struct{
	int color;
	vector<int> adjs;
} Vertex;

list<int> auxList;

bool DFS(Vertex *graph, int curIndex, int toColor){
	graph[curIndex].color = toColor;
	for(int i = 0; i < graph[curIndex].adjs.size(); ++i){
		int index = graph[curIndex].adjs[i];
		
		if(graph[index].color == WHITE){
			if(!DFS(graph, index, !toColor))
				return false;
		}
		if(graph[index].color == toColor)
			return false;
	}
	return true;
}

int main(){
	Vertex graph[200];
	int nVertices, nEdges;
	
	while(cin >> nVertices and nVertices){
		cin >> nEdges;

		for(int i = 0; i < 200; ++i){
			graph[i].color = WHITE;
			graph[i].adjs.clear();
		}

		for(int i = 0; i < nEdges; ++i){
			int x, y;
			cin >> x >> y;

			graph[x].adjs.push_back(y);
			graph[y].adjs.push_back(x);
		}

		bool flag = true;
		int toColor = BLACK;

		for(int i = 0; i < nVertices and flag; ++i){
			if(graph[i].color == WHITE)
				flag = DFS(graph, i, toColor);
		}

		if(flag)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

	return 0;
}