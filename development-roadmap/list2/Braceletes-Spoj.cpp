#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string pattern, s, sReversed;
		cin >> pattern >> s;

		sReversed = s;
		for(int i = 0, j = s.size()-1; i != j and i < j ; ++i, j--)
			sReversed[i] = s[j], sReversed[j] = s[i];

		sReversed += sReversed;
		s += s;

		if(s.find(pattern) != string::npos or sReversed.find(pattern) != string::npos)
			printf("S\n");
		else
			printf("N\n");
	}

	return 0;
}