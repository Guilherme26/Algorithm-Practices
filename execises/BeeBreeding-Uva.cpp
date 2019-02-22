#include <bits/stdc++.h>

using namespace std;

void coord(int droneCoordinate, int *X, int *Y){
	int i = 0, moveDown = 1, moveLeftUp = 1, moveUp = 1, moveRightUp = 1, moveRightDown = 1, moveLeftDown = 0;
	droneCoordinate--;
	while(droneCoordinate > 0){
		for(i = 0; i < moveDown && droneCoordinate > 0; i++){
			*Y += 1;
			droneCoordinate--;
		}
		for(i = 0; i < moveLeftDown && droneCoordinate > 0; i++){
			*Y += 1;
			*X -= 1;
			droneCoordinate--;
		}
		for(i = 0; i < moveLeftUp && droneCoordinate > 0; i++){
			*X -= 1;
			droneCoordinate--;
		}
		for(i = 0; i < moveUp && droneCoordinate > 0; i++){
			*Y -= 1;
			droneCoordinate--;
		}
		for(i = 0; i < moveRightUp && droneCoordinate > 0; i++){
			*X += 1;
			*Y -= 1;
			droneCoordinate--;
		}
		for(i = 0; i < moveRightDown && droneCoordinate > 0; i++){
			*X += 1;
			droneCoordinate--;
		}

		moveLeftUp = moveUp = moveRightUp = moveRightDown = ++moveDown;
		moveLeftDown++;

	}
}

int main(){
	int droneCoordinate1 = 0, droneCoordinate2 = 0;
	while(cin >> droneCoordinate1 >> droneCoordinate2 and droneCoordinate1 and droneCoordinate2){
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

		coord(droneCoordinate1, &x1, &y1);
		coord(droneCoordinate2, &x2, &y2);

		printf("The distance between cells %d and %d is %d.\n", droneCoordinate1, droneCoordinate2, max(max(abs(x1-x2), abs(y1-y2)), abs(x1+y1-x2-y2)));
	}
	return 0;
}