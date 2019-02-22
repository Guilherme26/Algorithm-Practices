#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
	int x,y;
	Point(){}
	Point(int _x, int _y){
		x = _x, y = _y;
	}

	bool operator >(const Point &p2)const{
		return (x>p2.x) or (x==p2.x and y>p2.y);
	}
} Point;

bool compare(const Point p1, const Point p2){
	return p1>p2;
}

void print(vector<Point> v){
	for(int i = 0; i < v.size(); ++i)
		printf("%d %d\n", v[i].x, v[i].y);
}

bool isInside(Point p1, Point p2, Point p3, Point p){
	int result1 = (p2.x - p1.x)*(p.y - p1.y) - (p2.y - p1.y)*(p.x - p1.x);
	int result2 = (p3.x - p2.x)*(p.y - p2.y) - (p3.y - p2.y)*(p.x - p2.x);
	int result3 = (p1.x - p3.x)*(p.y - p3.y) - (p1.y - p3.y)*(p.x - p3.x);

	int final = false;
	if(result1 > 0 and result2 > 0 and result3 > 0)
		final = true;

	result1 = (p2.x - p1.x)*(p.y - p1.y) - (p2.y - p1.y)*(p.x - p1.x);
	result2 = (p3.x - p2.x)*(p.y - p2.y) - (p3.y - p2.y)*(p.x - p2.x);
	result3 = (p1.x - p3.x)*(p.y - p3.y) - (p1.y - p3.y)*(p.x - p3.x);

	if(result1 < 0 and result2 < 0 and result3 < 0)
		final = true;

	return final;
}

int main(){
	int n,m;

	while(scanf("%d %d", &n, &m) == 2){
		vector<Point> nPoints, mPoints;
		int x,y;

		for(int i = 0; i < n; ++i){
			scanf("%d %d", &x,&y);
			nPoints.push_back(Point(x,y));
		}
		
		for(int i = 0; i < m; ++i){
			scanf("%d %d", &x,&y);
			mPoints.push_back(Point(x,y));
		}

		int sum = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				for(int k = j+1; k < n; ++k){
					int c = 0;
					for(int l = 0; l < m; ++l)
						if(isInside(nPoints[i], nPoints[j], nPoints[k], mPoints[l]))
							c += 1;
			 		
					sum += (c*c);
				}
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}