#include <bits/stdc++.h>

using namespace std;

int arrivalTime[1440];

int main(){
	int c, n, t, m;
	cin >> c;
	while(c--){
		cin >> n >> t >> m;
		for(int i = 0; i < m; ++i){
			cin >> arrivalTime[i];
		}

		int minutes = 0, trips = 0;
		for(int i = (m+n-1)%n; i < m; i += n){
			if(arrivalTime[i] <= minutes)
				minutes += 2*t;
			else
				minutes = arrivalTime[i] + 2*t;
			trips += 1;
		}
		// Balsa nao volta, então (-t)
		printf("%d %d\n", minutes-t, trips);
	}
	return 0;
}