#include <bits/stdc++.h>

using namespace std;

#define BLACK 1
#define WHITE 0

typedef struct{
	int origin, weight, destiny;
} Edge;

typedef struct{
	int color;
	long long int dist;
	vector<Edge> adjs, tmp;
} Vertex;

Vertex graph[40005];
int V;

void Dijkstra(int origin){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	// Cost and Index
	pq.push(make_pair(0, origin));

	while(pq.size()){
		pair<int, int> top = pq.top();
		pq.pop();

		int minVertex = top.second;
		if(graph[minVertex].color == BLACK)
			continue;
		graph[minVertex].color = BLACK;
		graph[minVertex].dist = top.first;

		for(int j = 0; j < graph[minVertex].adjs.size(); ++j){
			int firstLevel = graph[minVertex].adjs[j].destiny;
			int firstWeight = graph[minVertex].adjs[j].weight;
			for(int k = 0; k < graph[firstLevel].adjs.size(); ++k){
				int secondLevel = graph[firstLevel].adjs[k].destiny;
				int secondWeight = graph[firstLevel].adjs[k].weight;
				pq.push(make_pair(graph[minVertex].dist + firstWeight + secondWeight, secondLevel));
			}
		}
	}
}

int main(){
	int A;

	cin >> V >> A;
	Edge e;
	for(int i = 0; i < A; ++i){
		cin >> e.origin >> e.destiny >> e.weight;

		graph[e.origin].color = graph[e.destiny].color = WHITE;
		graph[e.origin].dist = graph[e.destiny].dist = INT_MAX;

		graph[e.origin].adjs.push_back(e);

		int aux = e.origin;
		e.origin = e.destiny;
		e.destiny = aux;

		graph[e.origin].adjs.push_back(e);
	}

	Dijkstra(1);

	if(graph[V].dist >= INT_MAX)
		printf("-1\n");
	else
		printf("%lld\n", graph[V].dist);

	return 0;
}