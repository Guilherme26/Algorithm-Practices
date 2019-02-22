#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define BLACK 0

typedef struct{
	int color;
	vector<int> adjs;
} Vertex;

Vertex graph[111];

void initialize(bool clear){
	for(int i = 0; i < 111; ++i){
		graph[i].color = WHITE;
		if(clear)
			graph[i].adjs.clear();
	}
}

void DFS(int initial){
	// printf("%d\n", initial);
	graph[initial].color = BLACK;
	for(int i = 0; i < graph[initial].adjs.size(); ++i){
		int curVertex = graph[initial].adjs[i];
		if(graph[curVertex].color)
			DFS(curVertex);
	}
}

int main(){
	int N;
	while(cin >> N and N){
		int V, VNg, criticals = 0;
		char scape;

		initialize(true);

		while(cin >> V and V){
			while(scanf("%d%c", &VNg, &scape) == 2){
				graph[V].adjs.push_back(VNg);
				graph[VNg].adjs.push_back(V);

				if(scape == '\n')
					break;
			}
		}

		for(int i = 1; i <= N; ++i){
			int calls = 0;
			graph[i].color = BLACK;

			for(int j = 1; j <= N; ++j){
				if(graph[j].color){
					DFS(j);
					calls += 1;
				}
			}

			initialize(false);
			if(calls > 1)
				criticals += 1;
		}

		printf("%d\n", criticals);
	}


	return 0;
}