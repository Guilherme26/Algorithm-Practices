#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	char op;
	cin >> a >> op >> b;

	for(int i = 0; i < a.size(); ++i) if(a[i] == '7') a[i] = '0';
	for(int i = 0; i < b.size(); ++i) if(b[i] == '7') b[i] = '0';

	int result = 0;
	switch(op){
		case '+':{
			result  = stoi(a)+stoi(b);
			a = to_string(result);
			for(int i = 0; i < a.size(); ++i) if(a[i] == '7') a[i] = '0';
			result = stoi(a);
			break;
		}
		case 'x':{
			result  = stoi(a)*stoi(b);
			a = to_string(result);
			for(int i = 0; i < a.size(); ++i) if(a[i] == '7') a[i] = '0';
			result = stoi(a);
			break;
		}
	}

	printf("%d\n", result);

	return 0;
}