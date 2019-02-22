#include <bits/stdc++.h>

using namespace std;

void printer(string row){
	int times = 0;
	for(int i = 0; i < row.size(); ++i){
		if(row[i] >= '1' && row[i] <= '9'){
			// 48 is the number of 0 on ASCII
			times += (row[i]-48);
		}
		else if(row[i] == '!'){
			printf("\n");
			times = 0;
		}
		else if(row[i] == 'b'){
			while(times--)
				printf(" ");
			times = 0;
		}
		else{
			while(times--){
				printf("%c", row[i]);
			}
			times = 0;
		}
	}
}

int main(){
	string row;
	while(getline(cin, row)){
		if(row == ""){
			printf("\n");
			row.clear();
			continue;
		}
		else{
			printer(row);
			printf("\n");
		}
		row.clear();
	}
	return 0;
}