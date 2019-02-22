#include <bits/stdc++.h>

using namespace std;

void printer(string s, bool &openned){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '\"'){
			if(openned)
				printf("``");
			else
				printf("''");
			openned = !openned;
		}
		else
			printf("%c", s[i]);
	}
	printf("\n");
}

int main(){
	string s;
	bool openned = true;
	while(getline(cin, s))
		printer(s, openned);

	return 0;
}