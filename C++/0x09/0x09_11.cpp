// https://www.acmicpc.net/problem/2206
// 2206번. 벽 부수고 이동하기

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

char board[1005][1005];
int vit[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> Q;
    int result = 0, wall = 0;

    vit[0][0];
    Q.push({0,0});

    while(!Q.empty()){
        auto pos = Q.front(); Q.pop();
        if(pos.X == n-1 && pos.Y == m-1){
            result = vit[pos.X][pos.Y];
            break;
        }

        for(int i=0; i < 4; i++){
            int mx = pos.X + dx[i];
            int my = pos.Y + dy[i];

            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(vit[mx][my] > 0) continue;
            if(board[mx][my] == '0'){
                vit[mx][my] = vit[pos.X][pos.Y] + 1;
                Q.push({mx,my});                
            }
            if(board[mx][my] == '1'){
                mx += dx[i];
                my += dy[i];
                if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
                if(vit[mx][my] > 0) continue;
                if(wall == 0 && board[mx][my] == '0'){
                    wall = 1;
                    vit[mx-dx[i]][my-dy[i]] = vit[pos.X][pos.Y] + 1;
                    vit[mx][my] = vit[pos.X][pos.Y] + 2;
                    Q.push({mx,my});
                }
            }
        }
    }
    if(result) cout << result+1 << "\n";
    else cout << -1 << "\n";
}

// 틀린 이유 : 벽을 한번만 부셔야 함.
// 틀린 이유 : ??