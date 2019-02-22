#include <bits/stdc++.h>

using namespace std;

int counter[12];

bool checkSquare(vector<vector< pair<char,char> > > board, int beginX, int beginY, int size){
	for(int column = beginY; column < beginY+size; column++){
		if(board[beginX][column].second != 'H')
			return false;
	}
	for(int line = beginX; line < beginX+size; line++){
		if(board[line][beginY].first != 'V')
			return false;
	}
	for(int column = beginY; column < beginY+size; column++){
		if(board[beginX+size][column].second != 'H')
			return false;
	}
	for(int line = beginX; line < beginX+size; line++){
		if(board[line][beginY+size].first != 'V')
			return false;	
	}
	return true;
}

int main(){
	int n, m, caso = 1;
	while(cin >> n){
		vector<vector< pair<char,char> > > board;
		cin >> m;

		for(int i = 0; i <= n; ++i){
			counter[i] = 0;
			vector< pair<char,char> > tmp;
			for(int j = 0; j <= n; ++j){
				tmp.push_back(pair<char,char>('n','n'));
			}
			board.push_back(tmp);
		}

		for(int i = 0; i < m; ++i){
			getchar();
			
			char o;
			int origin, destiny;
			scanf("%c %d %d", &o, &origin, &destiny);

			if(o == 'H')
				board[origin][destiny].second = o;
			else
				board[destiny][origin].first = o;
		}

		for(int beginX = 1; beginX < n; beginX++){
			for(int beginY = 1; beginY < n; beginY++){
				for(int size = 1; size < n; ++size){
					if(beginX+size <= n and beginY+size <= n){
						if(checkSquare(board, beginX, beginY, size))
							counter[size] += 1;
					}
				}
			}
		}


		if(caso > 1)
			printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", caso);

		bool flag = false;
		for(int size = 1; size < n; ++size){
			if(counter[size] > 0){
				flag = true;
				printf("%d square (s) of size %d\n", counter[size], size);
			}
		}

		if(!flag)
			printf("No completed squares can be found.\n");

		caso += 1;
	}

	return 0;
}