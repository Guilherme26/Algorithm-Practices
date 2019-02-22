#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	
	while(scanf("%d", &n) and n){
		int sheet = 1, tail = n, head = 1;
		printf("Printing order for %d pages:\n", n);

		if(n%4 == 1){
			if(n > 4){
				printf("Sheet %d, front: Blank, %d\n", sheet, head);
				head++;
				printf("Sheet %d, back : %d, Blank\n", sheet, head);
				head++;
				sheet++;
				printf("Sheet %d, front: Blank, %d\n", sheet, head);
				head++;
			}
			else{
				printf("Sheet %d, front: Blank, %d\n", sheet, head);
				head++;
			}
		}
		else if(n%4 == 3){
			printf("Sheet %d, front: Blank, %d\n", sheet, head);
			head++;
		}
		else if(n%4 == 2){
			printf("Sheet %d, front: Blank, %d\n", sheet, head);
			head++;
			printf("Sheet %d, back : %d, Blank\n", sheet, head);
			head++;
			sheet++;
		}


		while(tail > head){
			if(head % 2)
				printf("Sheet %d, front: %d, %d\n", sheet, tail, head);
			else{
				printf("Sheet %d, back : %d, %d\n", sheet, head, tail);
				sheet++;
			}

			tail--, head++;
		}
	}

	return 0;
}