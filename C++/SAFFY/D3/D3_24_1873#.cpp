// 1873

// memset() 해주니까 Pass

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>

#define X first
#define Y second

using namespace std;

char board[25][25];

int dx[4] = {0,1,0,-1}; // L, D, R, U
int dy[4] = {-1,0,1,0};

int dir = 0;

pair<int, int> pos;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++){
		int H, W;
		cin >> H >> W;

		memset(board, 0, sizeof(board));

		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cin >> board[i][j];

				if(board[i][j] == '<'){
					pos.X = i;
					pos.Y = j;
					dir = 0;
				}
				else if(board[i][j] == 'v'){
					pos.X = i;
					pos.Y = j;
					dir = 1;
				}
				else if(board[i][j] == '>'){
					pos.X = i;
					pos.Y = j;
					dir = 2;
				}
				else if(board[i][j] == '^'){
					pos.X = i;
					pos.Y = j;
					dir = 3;
				}
			}
		}

		int len; 
		string str;

		cin >> len >> str;

		for(int i = 0; i < len; i++){
			if(str[i] == 'S'){
				int mx = pos.X;
				int my = pos.Y;

				while(1){
					mx += dx[dir];
					my += dy[dir];

					if(mx < 0 || my < 0 || mx > H || my > W){ break; }
					if(board[mx][my] == '#'){ break; }
					if(board[mx][my] == '*'){
						board[mx][my] = '.';
						break;
					}
				}
			}
			else if(str[i] == 'L'){
				dir = 0;
				board[pos.X][pos.Y] = '<';

				int mx = pos.X + dx[dir];
				int my = pos.Y + dy[dir];

				if(mx < 0 || my < 0 || mx > H || my > W){ continue; }
				if(board[mx][my] == '#' || board[mx][my] == '*' || board[mx][my] == '-'){ continue; }
				if(board[mx][my] == '.'){
					board[pos.X][pos.Y] = '.';
					pos.X = mx;
					pos.Y = my;
					board[pos.X][pos.Y] = '<';
				}
			}
			else if(str[i] == 'D'){
				dir = 1;
				board[pos.X][pos.Y] = 'v';

				int mx = pos.X + dx[dir];
				int my = pos.Y + dy[dir];

				if(mx < 0 || my < 0 || mx > H || my > W){ continue; }
				if(board[mx][my] == '#' || board[mx][my] == '*' || board[mx][my] == '-'){ continue; }
				if(board[mx][my] == '.'){
					board[pos.X][pos.Y] = '.';
					pos.X = mx;
					pos.Y = my;
					board[pos.X][pos.Y] = 'v';
				}
			}
			else if(str[i] == 'R'){
				dir = 2;
				board[pos.X][pos.Y] = '>';

				int mx = pos.X + dx[dir];
				int my = pos.Y + dy[dir];

				if(mx < 0 || my < 0 || mx > H || my > W){ continue; }
				if(board[mx][my] == '#' || board[mx][my] == '*' || board[mx][my] == '-'){ continue; }
				if(board[mx][my] == '.'){
					board[pos.X][pos.Y] = '.';
					pos.X = mx;
					pos.Y = my;
					board[pos.X][pos.Y] = '>';
				}
			}
			else if(str[i] == 'U'){
				dir = 3;
				board[pos.X][pos.Y] = '^';

				int mx = pos.X + dx[dir];
				int my = pos.Y + dy[dir];

				if(mx < 0 || my < 0 || mx > H || my > W){ continue; }
				if(board[mx][my] == '#' || board[mx][my] == '*' || board[mx][my] == '-'){ continue; }
				if(board[mx][my] == '.'){
					board[pos.X][pos.Y] = '.';
					pos.X = mx;
					pos.Y = my;
					board[pos.X][pos.Y] = '^';
				}
			}
		}
		
		cout << "#" << test_case << " ";
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cout << board[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}