#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, value, c=1, b=0;
	vector<int> v;

	scanf("%d", &n);
	while(n--){
		scanf("%d", &value);
		v.push_back(value);
	}

	for(int i=1; i<v.size(); i++){
		if(v[i-1]<=v[i])
			c+=1;
		else{
			if(c > b)
				b=c;
			c=1;	
		}
	}

	if(c > b)
		b=c;

	printf("%d\n", b);
	return 0;
}