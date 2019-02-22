#include <bits/stdc++.h>

#define llu long long

using namespace std;

int main(){
	int v[20005], c, n;

	scanf("%d", &c);
	for(int i = 1; i <= c; ++i){
		scanf("%d", &n);

		// Left 0th position unused
		for(int j = 1; j < n; ++j)
			scanf("%d", &v[j]);

		llu sum=0,max=0;
		int a=0,b=0,c=0;
		for(int j = 1; j < n; ++j){
			sum += v[j];
            if(sum > max || (sum == max && j - a > b - c)) {
                max = sum;
                b = j;
                c = a;
            }
            if(sum < 0) {
                a = j;
                sum = 0;
            }
		}
		if(max > 0)
			printf("The nicest part of route %d is between stops %d and %d\n", i, c+1, b+1);
		else
			printf("Route %d has no nice parts\n", i);
	}

	return 0;
}