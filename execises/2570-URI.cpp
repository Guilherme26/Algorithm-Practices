#include <bits/stdc++.h>

using namespace std;

int nxm[1010][1010];

int main(){
	int n,m,k,v;
	char c;

	for(int i = 0; i < 1010; ++i) for(int j = 0; j < 1010; ++j) nxm[i][j] = 4;

	scanf("%d %d %d\n", &n, &m, &k);
	for(int i = 0; i < k; ++i){
		scanf("%c %d\n", &c, &v);
		if(c == 'L') for(int j = 1; j <= m; ++j) nxm[v][j] = i%4;
		if(c == 'C') for(int j = 1; j <= n; ++j) nxm[j][v] = i%4;
	}

	int ans[5] = {0,0,0,0,0};
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) ans[nxm[i][j]]++;

	printf("R%d H%d C%d P%d\n", ans[0], ans[1], ans[2], ans[3]);
	return 0;
}