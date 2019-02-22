#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int l,c,x,y;
	cin >> l >> c >> x >> y;

	if((x*c+y)%2)
		printf("Esquerda\n");
	else
		printf("Direita\n");

	return 0;
}