#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define BLACK 0

typedef struct{
	int color;
	vector<int> adjs;
	vector<int> aux;
} Vertex;

Vertex graph[2005];

void getTransposed(int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < graph[i].adjs.size(); ++j){
			int curIndex = graph[i].adjs[j];
			graph[curIndex].aux.push_back(i);
		}
	}
	for(int i = 1; i <= n; ++i){
		graph[i].adjs.swap(graph[i].aux);
		graph[i].color = WHITE;
	}
}

bool check(vector<int> sol){
	for(int i = 0; i < sol.size()-1; ++i){
		if(sol[i] == -1)
			return false;
	}
	return true;
}

void DFSOrder(int index, vector<int> &sol){
	graph[index].color = BLACK;

	for(int i = 0; i < graph[index].adjs.size(); ++i){
		int curIndex = graph[index].adjs[i];
		if(graph[curIndex].color)
			DFSOrder(curIndex, sol);
	}
	sol.push_back(index);
}

void DFSSOL(int index, vector<int> &sol){
	graph[index].color = BLACK;
	sol.push_back(index);

	for(int i = 0; i < graph[index].adjs.size(); ++i){
		int curIndex = graph[index].adjs[i];
		if(graph[curIndex].color)
			DFSSOL(curIndex, sol);
	}
}


int main(){
	int n,m, begin = 1, cont = 1;
	while(cin >> n >> m and n){
		if(!begin)
			printf("\n");
		for(int i = 1; i < 2005; ++i){
			graph[i].color = WHITE;
			graph[i].adjs.clear();
			graph[i].aux.clear();
		}

		int b, e;
		for(int i = 0; i < m; ++i){
			cin >> b >> e;

			graph[b].adjs.push_back(e);
			graph[e].adjs.push_back(b);
		}

		vector<int> entry;
		for(int i = 1; i <= n; ++i){
			if(graph[i].color){
				DFSOrder(i, entry);
			}
		}

		getTransposed(n);

		vector<int> closing;
		for(int i = entry.size()-1; i >= 0; i--){
			int curIndex = entry[i];
			if(graph[curIndex].color){
				DFSSOL(curIndex, closing);
				closing.push_back(-1);
			}
		}

		if(check(closing))
			printf("Teste %d\nnormal\n", cont);
		else
			printf("Teste %d\nfalha\n", cont);
		begin = 0, cont++;
	}

	return 0;
}