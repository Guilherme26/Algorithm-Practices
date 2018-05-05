#include <bits/stdc++.h>

using namespace std;

int gdc(int x, int y){
	if(x == 0)
        return y;
    return gdc(y%x, x);
}

long long int c(string s){
	long long int num;
	for(int i = s.size()-1, j=0; i >= 0; --i, j++){
		char c = s[i];
		num += 0|atoi(&c)<<j;
	}
	return num;
}

int main(){
	int n, count = 0;
	cin >> n;
	while(n--){
		string s1, s2;
		cin >> s1 >> s2;

		long long int x = c(s1), y = c(s2);

		count += 1;
		if(x==y){
			printf("Pair #%d: All you need is love!\n", count);
			continue;
		}

		if(gdc(x,y) > 1)
			printf("Pair #%d: All you need is love!\n", count);
		else
			printf("Pair #%d: Love is not all you need!\n", count);
	}


	return 0;
}