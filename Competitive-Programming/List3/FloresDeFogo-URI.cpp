#include <bits/stdc++.h>

using namespace std;

int main(){
	int r1,r2,x1,x2,y1,y2;
	while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){
		float hip = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
		if(r1 >= r2+hip)
			printf("RICO\n");
		else
			printf("MORTO\n");
	}

	return 0;
}