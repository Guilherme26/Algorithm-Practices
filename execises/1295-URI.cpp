#include <stdio.h>
#include <math.h>

double v[10000][2];

int main(){
	int n,i,j;
	while(scanf("%d", &n) && n){
		for(i = 0; i < n; ++i)
			scanf("%lf %lf", &v[i][0], &v[i][1]);

		double result = (double)0x3f3f3f3f, tmp = 0.0;
		for(i = 0; i < n; ++i){
			for(j = i+1; j < n; ++j){
				tmp = sqrt(pow(v[i][0]-v[j][0],2) + pow(v[i][1]-v[j][1],2));
				if(result > tmp)
					result = tmp;
			}
		}

		if(result<10000)
			printf("%.4f\n", result);
		else
			printf("INFINITY\n");
	}

	return 0;
}