#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	while(n--){
		string s, ans;
		cin >> s;
		ans = s;

		if(s.size() == 1){
			printf("%s: O\n", ans.c_str());
			continue;
		}

		for(int i = 0; i < s.size(); ++i)
			s[i] = tolower(s[i]);

		bool unnordered = false;
		for(int i = 1; i < s.size(); ++i){
			char lastChar = s[i-1], curChar = s[i];
			if(lastChar >= curChar){
				unnordered = true;
				break;
			}
		}

		if(unnordered)
			printf("%s: N\n", ans.c_str());
		else
			printf("%s: O\n", ans.c_str());
	}

	return 0;
}