#include <bits/stdc++.h>

using namespace std;

int main(){
	int lado, hipotenusa;
	double PI = 3.1415926535;

	cin >> lado >> hipotenusa;
	if(lado/2 >= hipotenusa)
		printf("%.3lf\n", PI*hipotenusa*hipotenusa);
	else if(lado*sqrt(2)/2 <= hipotenusa)
		printf("%.3lf\n", lado*lado*1.0);
	else{
		double cateto1 = lado/2.0, theta = acos(cateto1/hipotenusa), alpha = PI/4 - theta, pArea1 = alpha*hipotenusa*hipotenusa*4, cateto2 = hipotenusa*sin(theta), pArea2 = cateto1 * cateto2*4;
		printf("%.3lf\n", pArea1+pArea2);
	}

	return 0;
}