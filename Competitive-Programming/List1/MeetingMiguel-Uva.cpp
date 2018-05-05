#include <bits/stdc++.h>

using namespace std;

long long int my[10000][10000], mm[10000][10000];

int shortestPath(int nVertices, char age){
	if(age == 'Y'){
		for(int k = 0; k < nVertices; ++k){
			for(int i = 0; i < nVertices; ++i){
				for(int j = 0; j < nVertices; ++j){
					if(my[i][j] > my[i][k] + my[k][j])
						my[i][j] = my[i][k] + my[k][j];
				}
			}
		}
	}
	else{
		for(int k = 0; k < nVertices; ++k){
			for(int i = 0; i < nVertices; ++i){
				for(int j = 0; j < nVertices; ++j){
					if(mm[i][j] > mm[i][k] + mm[k][j])
						mm[i][j] = mm[i][k] + mm[k][j];
				}
			}
		}
	}
}

int main(){
	int nVertices;
	while(cin >> nVertices and nVertices){

		char age, direction, origin, destiny;
		int weight, maxVertices = 0;

		for(int i = 0; i < 10000; ++i){
			for(int j = 0; j < 10000; ++j)
				my[i][j] = INT_MAX, mm[i][j] = INT_MAX;
			my[i][i] = 0, mm[i][i] = 0;
		}

		for(int i = 0; i < nVertices; ++i){
			getchar();
			scanf("%c %c %c %c %d", &age, &direction, &origin, &destiny, &weight);

			origin -= 'A', destiny -= 'A';

			if(origin == destiny)
				continue;

			if(origin > maxVertices)
				maxVertices = origin;
			if(destiny > maxVertices)
				maxVertices = destiny;

			if(age == 'Y'){
				if(direction == 'B'){
					my[origin][destiny] = weight;
					my[destiny][origin] = weight;
				}
				else
					my[origin][destiny] = weight;
			}
			else{
				if(direction == 'B'){
					mm[origin][destiny] = weight;
					mm[destiny][origin] = weight;
				}
				else
					mm[origin][destiny] = weight;
			}
		}

		maxVertices++;

		char fOrigin, sOrigin;
		cin >> fOrigin >> sOrigin;
		fOrigin -= 'A', sOrigin -= 'A';

		shortestPath(maxVertices, 'Y');
		shortestPath(maxVertices, 'M');

		long long int smallest = INT_MAX;
		int smlIndex = -1;
		for(int i = 0; i < maxVertices; ++i){
			if(my[fOrigin][i]+mm[sOrigin][i] < smallest){
				smallest = my[fOrigin][i]+mm[sOrigin][i];
				smlIndex = i;
			}
		}

		if(smallest >= INT_MAX)
			printf("You will never meet.\n");
		else{
			if(fOrigin == sOrigin){
				smallest = 0;
				smlIndex = fOrigin;
			}
			
			printf("%lld %c", smallest, smlIndex+'A');
			for(int i = smlIndex+1; i < maxVertices; ++i){
				if(my[fOrigin][i]+mm[sOrigin][i] == smallest)
					printf(" %c", i+'A');
			}
			printf("\n");
		}

	}
	return 0;
}