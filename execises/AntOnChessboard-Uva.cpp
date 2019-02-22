#include <bits/stdc++.h>

using namespace std;

long long int jump, seconds, x, y;

int main(){
	long long int n;
	while(scanf("%lld", &n) and n){
		int sqRoot = sqrt(n);
		jump=1, x=1, y=1;

		if(n == sqRoot*sqRoot){	
			if(n%2 == 0)
				printf("%lld %lld\n", x+sqRoot-1, y);
			else if(n%2 == 1)
				printf("%lld %lld\n", x, y+sqRoot-1);
			continue;
		} 
		else{

			seconds = n - sqRoot*sqRoot-1;
			jump = sqRoot;

			if(sqRoot%2 == 0){
				x = sqRoot+1;
				if(seconds <= jump){
					y += seconds;
				}
				else{
					y += jump;
					x -= abs(seconds-jump);
				}
			}
			else if(sqRoot%2 == 1){
				y = sqRoot+1;
				if(seconds <= jump){
					x += seconds;
				}
				else{
					x += jump;
					y -= abs(seconds-jump);
				}
			}
		}


		printf("%lld %lld\n", x, y);
	}

	return 0;
}