#include <bits/stdc++.h>

using namespace std;

#define NEUTRAL 0
#define POSITIVE 1
#define NEGATIVE -1
int st[1000010], vec[2000010];

int findSignal(int x){
	if(x > 0)
		return POSITIVE;
	if(x < 0)
		return NEGATIVE;
	return NEUTRAL;
}

void printSignal(int x){
	if(x == POSITIVE)
		printf("+");
	else if(x == NEGATIVE)
		printf("-");
	else
		printf("0");
}

void createSG(int index, int left, int right){
	if(left > right)
		return;
	if(left==right)
		st[index] = vec[left];
	else{
		createSG(2*index, left, (right+left)/2);
		createSG(2*index+1, (right+left)/2+1, right);

		st[index] = st[2*index] * st[2*index+1];
	}
}

int query(int index, int left, int right, int leftBound, int rightBound){
	if(left > right or rightBound < left or leftBound > right)
		return 1;
	if(leftBound <= left and right <= rightBound)
		return st[index];

	return query(2*index, left, (right+left)/2, leftBound, rightBound) * 
		query(2*index+1, (right+left)/2+1, right, leftBound, rightBound);
}

void updLog(int index, int left, int right, int updIndex, int value){
	if(left > right or updIndex < left or updIndex > right)
		return;
	if(left==right and left==updIndex){
		st[index] = findSignal(value);
		return;
	}
	if(left==right)
		return;

	if(updIndex <= (left+right)/2)
		updLog(2*index, left, (left+right)/2, updIndex, value);
	if(updIndex > (left+right)/2)
		updLog(2*index+1, (left+right)/2+1, right, updIndex, value);

	st[index] = st[2*index]*st[2*index+1];
}

int main(){
	int vecSize, turns, x, y;
	string action;

	while(cin >> vecSize >> turns){
		for(int i = 1; i <= vecSize; ++i){
			cin >> vec[i];
			vec[i] = findSignal(vec[i]);
		}

		createSG(1,1,vecSize);
		for(int i = 0; i < turns; ++i){
			cin >> action >> x >> y;
			if(action == "C")
				updLog(1,1,vecSize,x,y);
			else if(action == "P")
				printSignal(findSignal(query(1,1,vecSize,x,y)));
		}
		printf("\n");
	}

	return 0;
}