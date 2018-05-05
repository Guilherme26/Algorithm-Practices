#include <bits/stdc++.h>

using namespace std;

int cycle(int k){
	int count = 1;
	while(k != 1){
		if(k % 2)
			k = 3*k + 1;
		else
			k /= 2;
		count += 1;
	}
	return count;
}

int main(){
	int i, j, aux;
	while(cin >> i >> j){
		cout << i << " " << j << " ";
		if(i > j){
			aux = i;
			i = j;
			j = aux;
		}
		
		int max = 0;
		for (int k = i; k <= j; ++k){
			int r = cycle(k);
			if(max < r)
				max = r;
		}
		cout << max << "\n";
	}

	return 0;
}