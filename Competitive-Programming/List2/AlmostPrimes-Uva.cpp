#include <bits/stdc++.h>  

using namespace std;  

vector<long long int> primes, primeNumbers, almost;

void sieve(){
	for(int i = 2; i < 1000001; ++i){
		if(primes[i]){
			primeNumbers.push_back(i);
			for(int j = i+i; j < 1000001; j += i)
				primes[j] = 0;
		}
	}
}

int main(){
	long long int N, low, high;

	cin >> N;
	primes.assign(1000001, 1);
	sieve();

	for(int i = 0; i < primeNumbers.size(); ++i)
		for(long long int j = primeNumbers[i]*primeNumbers[i]; j <= 1000000000000; j *= primeNumbers[i])
			almost.push_back(j);

	sort(almost.begin(), almost.end());

	while(N--){
		cin >> low >> high;
		
		long long int count = 0;

		for(int i = 0; almost[i] <= high; ++i){
			if(almost[i] >= low)
				count += 1;
		}

		printf("%lld\n", count);
	}

	return 0;
}