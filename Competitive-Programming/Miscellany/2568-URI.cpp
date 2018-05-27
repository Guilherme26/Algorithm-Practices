#include <bits/stdc++.h>

using namespace std;

int main(){
	int d,i,x,f;
	cin >> d >> i >> x >> f;

	if(d%2 == 0){
		if(f%2 == 0)
			cout << i << endl;
		else
			cout << i-x << endl;
	}
	
	if(d%2 == 1){
		if(f%2 == 0)
			cout << i << endl;
		else
			cout << i+x << endl;
	}

	return 0;
}