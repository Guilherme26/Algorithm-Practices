/*
	Guilherme Resende - 2018
	The code below is for finding (if exists) the index of an 
	occurrence of an item in a vector. A binary search performs 
	each query in time complexity of O(ln n).
*/

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