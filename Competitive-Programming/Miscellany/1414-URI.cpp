#include <bits/stdc++.h>

using namespace std;

int main(){
	int T = 0, P = 0, tied = 0, pts = 0;
	while(cin >> T >> P and T){
		tied = 3*P;
		string s;
		for(int i = 0; i < T; ++i){
			cin >> s >> pts;
			tied -= pts;
		}
		printf("%d\n", tied);
	}


	return 0;
}