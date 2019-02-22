#include <bits/stdc++.h>

using namespace std;

#define OUTSIDE 0
int st[1000010], vec[200010];

void createSG(int index, int left, int right){
	if(left > right)
		return;
	if(left==right)
		st[index] = vec[left];
	else{
		createSG(2*index, left, (right+left)/2);
		createSG(2*index+1, (right+left)/2+1, right);

		st[index] = st[2*index] + st[2*index+1];
	}
}

int query(int index, int left, int right, int leftBound, int rightBound){
	if(left > right or rightBound < left or leftBound > right)
		return OUTSIDE;
	if(leftBound <= left and right <= rightBound)
		return st[index];

	return query(2*index, left, (right+left)/2, leftBound, rightBound) + 
		query(2*index+1, (right+left)/2+1, right, leftBound, rightBound);
}

void updLog(int index, int left, int right, int updIndex, int value){
	// printf("l:%d r:%d i:%d ui:%d %d %d\n", left,right,index,updIndex, st[index], value);

	if(left > right)
		return;
	if(left==right and left==updIndex){
		st[index] = value;
		// printf("%d\n", st[index]);
		return;
	}
	if(left==right)
		return;

	if(updIndex <= (left+right)/2)
		updLog(2*index, left, (left+right)/2, updIndex, value);
	if(updIndex > (left+right)/2)
		updLog(2*index+1, (left+right)/2+1, right, updIndex, value);

	st[index] = st[2*index]+st[2*index+1];
}

int main(){
	int vecSize,x,y,caso = 1;
	char buffer[500], action[4];

	while(scanf("%d", &vecSize) and vecSize){
		for(int i = 1; i <= vecSize; ++i)
			scanf("%d", &vec[i]);
		
		getchar();
		createSG(1, 1, vecSize);

		if(caso != 1)
			printf("\n");
		printf("Case %d:\n", caso++);	
		while(1){
			fgets(buffer,500,stdin);
			sscanf(buffer, "%s %d %d", action, &x, &y);

			char c = buffer[0];
			if(c == 'S')
				updLog(1, 1, vecSize, x, y);
			else if(c == 'M')
				printf("%d\n", query(1, 1, vecSize, x, y));
			else
				break;
		}
	}


	return 0;
}