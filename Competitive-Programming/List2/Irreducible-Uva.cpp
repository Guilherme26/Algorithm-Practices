#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<int> primesIndices;

void sieve(){
	for(int i = 2; i < primes.size(); ++i)
		if(primes[i]){
			primesIndices.push_back(i);
			for(int j = i+i; j < primes.size(); j += i)
				primes[j] = 0;
		}
}

long long int Phi(long long int n){
	long long int result = n;

	bool flag = true;
	for(int i = 0; i < primesIndices.size() and n > 1; i++){
		int prime = primesIndices[i];
		while(n%prime==0){
			n /= prime;
			if(flag){
				result *= (1 - 1.0/prime);
				flag = false;
			}
		}
		flag = true;
	}

	if(n > 1)
		result *= (1 - 1.0/n);

	return result;
}

int main(){
	long long int n;
	primes.assign(sqrt(1000000000)+1, 1);

	sieve();

	while(cin >> n and n){
		if(n == 1)
			printf("1\n");
		else
			printf("%lld\n", Phi(n));
	}

	return 0;
}