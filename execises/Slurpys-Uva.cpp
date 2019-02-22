#include <bits/stdc++.h>

using namespace std;

bool isSlump(string s, int *index, int state){
	if(*index == s.size())
		return false;

	char c = s[*index];
	switch(state){
		case 1:{
			if(c == 'D' or c == 'E'){
				*index += 1;
				return isSlump(s, index, state+1);
			}
			return false;
			break;
		}
		case 2:{
			if(c == 'F'){
				char c2 = s[*index+1];
				*index += 1;

				if(c2 == 'F')
					return isSlump(s, index, state);
				if(c2 == 'G')
					return isSlump(s, index, state+1);
				return isSlump(s, index, 1);
			}
			return false;	
			break;
		}
		case 3:{
			if(c == 'G')
				return true;
			if(c == 'D' || c == 'E'){
				*index += 1;
				return isSlump(s, index, 1);
			}
			return false;
		}
	}
}


bool isSlimp(string s, int *index, int state){
	if(*index == s.size())
		return false;

	char c = s[*index];
	switch(state){
		case 1:{
			if(c == 'A'){				
				*index += 1;
				return isSlimp(s, index, state+1);
			}
			return false;
			break;
		}
		case 2:{
			if(c == 'H'){
				return true;
			}
			if(c == 'B'){
				*index += 1;
				if(isSlimp(s, index, 1)){
					*index += 1;
					return isSlimp(s, index, state+1);
				}
				return false;
			}
			if(isSlump(s, index, 1)){
				*index += 1;
				return isSlimp(s, index, state+1);
			}
			return false;
			break;
		}
		case 3:{
			if(c == 'C')
				return true;
			return false;
			break;
		}
	}
}


int main(){
	int n;
	cin >> n;

	printf("SLURPYS OUTPUT\n");
	while(n--){
		string s;
		cin >> s;

		int index = 0;
		if(isSlimp(s, &index, 1) and index++ and isSlump(s, &index, 1) and index == s.size()-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}