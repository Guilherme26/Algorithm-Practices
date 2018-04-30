/*
	Guilherme Resende - 2018
	The code below is for finding the smallest path between 'S' and 
	any other vertex on a weighted, directed graph without negative 
	cicles or edges. Dijkstra's algorithm - as implemented here - solve the 
	aforementioned problem with O(n+m*ln(m)) time complexity.
*/

using namespace std;
 
#define WHITE 1
#define BLACK 0
typedef pair<int, int> pii;
typedef struct{
	long long int dist;
	vector<pii> adjs;
} Vertex;
 
Vertex graph[110];
int color[110];

void Dijkstra(int s){
	priority_queue<pii, vector< pii >, greater< pii > > pq;
	pq.push(make_pair(0, s));
 
	while(pq.size()){
		pii u = pq.top(); pq.pop();
		if(color[u.second] == BLACK)
			continue;
		color[u.second] = BLACK;
		graph[u.second].dist = u.first;
 
		for(int i = 0; i < graph[u.second].adjs.size(); ++i){
			pii cn = graph[u.second].adjs[i];
			pq.push(make_pair(graph[u.second].dist + cn.first, cn.second));
		}
	}
}