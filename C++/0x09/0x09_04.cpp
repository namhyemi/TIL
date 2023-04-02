// https://www.acmicpc.net/problem/7562
// 7562번. 나이트의 이동

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[305][305];

int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    
    while(num--){
        int size;
        cin >> size;

        queue<pair<int,int>> Q;
        pair<int,int> start_pos, end_pos;

        cin >> start_pos.X >> start_pos.Y;
        cin >> end_pos.X >> end_pos.Y;

        fill(&board[0][0], &board[size][size], 0);

        board[start_pos.X][start_pos.Y] = 1;
        Q.push({start_pos.X, start_pos.Y});


        while(!Q.empty()){
            pair<int,int> pos = Q.front(); Q.pop();
            if(pos.X == end_pos.X && pos.Y == end_pos.Y){
                cout << board[pos.X][pos.Y] - 1 << "\n";
                break;
            }

            for(int k=0; k < 8; k++){
                int mx = pos.X + dx[k];
                int my = pos.Y + dy[k];

                if(mx < 0 || my < 0 || mx >= size || my >= size) continue;
                if(board[mx][my] > 0) continue;

                board[mx][my] = board[pos.X][pos.Y] + 1;
                Q.push({mx, my}); 
            }
        }
        // cout << board[end_pos.X][end_pos.Y] << "\n";
    }
}

// 틀린 이유 : 테스트 케이스 여러개 돌리는 경우에는 초기화 주의.