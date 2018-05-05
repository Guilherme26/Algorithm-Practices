#include <bits/stdc++.h>

using namespace std;

#define BOTTOM_LEFT_X 0
#define BOTTOM_LEFT_Y 0
#define NORTH 90
#define EAST 180
#define WEST 360
#define SOUTH 270
#define LOST -1
#define SUCCEED 1

vector< pair<int,int> > avoided;
int TOP_RIGHT_X, TOP_RIGHT_Y;
char O;

bool isAvoided(int x, int y){
	for(const pair<int,int> &b : avoided){
		if(x == b.first and y == b.second)
			return true;
	}
	return false;
}

int move(int *x, int *y, int orientation){
	if(orientation == NORTH or orientation == SOUTH){
		if(orientation == NORTH){
			if(*y+1 > TOP_RIGHT_Y and not(isAvoided(*x,*y))){
				avoided.push_back(pair<int,int>(*x,*y));
				return LOST;
			}
			if(*y+1 <= TOP_RIGHT_Y and *y+1 >= 0)
				*y += 1;
		}
		else{
			if(*y-1 < 0 and not(isAvoided(*x,*y))){
				avoided.push_back(pair<int,int>(*x,*y));
				return LOST;
			}
			if(*y-1 <= TOP_RIGHT_Y and *y-1 >= 0)
				*y -= 1;
		}
		return SUCCEED;
	}
	else{
		if(orientation == EAST){
			if(*x+1 > TOP_RIGHT_X and not(isAvoided(*x,*y))){
				avoided.push_back(pair<int,int>(*x,*y));
				return LOST;
			}
			if(*x+1 <= TOP_RIGHT_X and *x >= 0)
				*x += 1;
		}
		else{
			if(*x-1 < 0 and not(isAvoided(*x,*y))){
				avoided.push_back(pair<int,int>(*x,*y));
				return LOST;
			}
			if(*x-1 <= TOP_RIGHT_X and *x-1 >= 0)
				*x -= 1;
		}
		return SUCCEED;	
	}
}

void upd(int orientation){
	switch(orientation){
		case NORTH:{
			O = 'N';
			break;
		}
		case SOUTH:{
			O = 'S';
			break;
		}
		case EAST:{
			O = 'E';
			break;
		}
		case WEST:
		case 0:{
			O = 'W';
			break;
		}
	}
}

int main(){
	scanf("%d %d", &TOP_RIGHT_X, &TOP_RIGHT_Y);

	int x, y, orientation = 0;
	string sequence;
	while(scanf("%d %d %c", &x, &y, &O) == 3){
		cin >> sequence;

		if(O == 'N')
			orientation = NORTH;
		else if(O == 'S')
			orientation = SOUTH;
		else if(O == 'E')
			orientation = EAST;
		else if(O == 'W')
			orientation = WEST;

		int flag = SUCCEED;
		for (int i = 0; i < sequence.size() and flag != LOST; ++i){
			char c = sequence[i];
			switch(c){
				case 'R':{
					orientation = (orientation + 90) % 360;
					if(orientation == 0)
						orientation = WEST;
					upd(orientation);
					break;
				}
				case 'L':{
					orientation = abs(orientation - 90) % 360;
					if(orientation == 0)
						orientation = WEST;
					upd(orientation);
					break;
				}
				case 'F':{
					if(move(&x,&y,orientation) == LOST)
						flag = LOST;
					break;
				}
			}
		}

		if(flag == LOST)
			printf("%d %d %c LOST\n", x,y,O);
		else
			printf("%d %d %c\n", x,y,O);
	}

	return 0;
}