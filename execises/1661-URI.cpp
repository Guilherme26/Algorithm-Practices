#include <bits/stdc++.h>

using namespace std;

int main(){
    long long v[100005];
    int n;

    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        
        for(int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);


        long long sum=0;
        for(int i = 1; i < n; ++i){
            if(v[i-1] < 0)
                sum += -v[i-1];
            else
                sum += v[i-1];

            v[i] += v[i-1];
        }
        printf("%lld\n", sum);
    }
    return 0;
}