#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
lli nums[100000];
int size;

int BinarySearch(lli item, int low, int high){
	int middle = (low + high)/2;
	if(middle < 0 or middle >= size or high < low)
		return -1;
	if(nums[middle] == item)
		return middle;

	if(nums[middle] < item)
		return BinarySearch(item, middle+1, high);
	else if(nums[middle] > item)
		return BinarySearch(item, 0, middle-1);
}


int main(){
	int q;
	lli tmp;
	
	scanf("%d %d", &size, &q);
	for(int i = 0; i < size; ++i)
		scanf("%lld", &nums[i]);

	for(int i = 0; i < q; ++i){
		scanf("%lld", &tmp);
		printf("%d\n", BinarySearch(tmp, 0, size));
	}

	return 0;
}