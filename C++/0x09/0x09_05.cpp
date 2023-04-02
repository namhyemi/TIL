// https://www.acmicpc.net/problem/5427
// 5427น๘. บา

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[1005][1005];
int vit[1005][1005];
int vit2[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    while(num--){
        int result = 0;
        int n, m;
        cin >> m >> n;

        queue<pair<int,int>> FIRE_Q, MAN_Q;

        fill(&vit[0][0], &vit[n][m], 0);
        fill(&vit2[0][0], &vit2[n][m], 0);
        fill(&board[0][0], &board[n][m], 0);

        for(int i = 0; i < n; i++){
            for(int j=0; j < m; j++){
                char ch;
                cin >> ch;
                
                if(ch == '#') board[i][j] = -1;
                else if(ch == '*'){
                    FIRE_Q.push({i,j});
                    vit[i][j] = 1;
                }
                else if(ch == '@'){
                    MAN_Q.push({i,j});
                    vit2[i][j] = 1;
                }
                else ;
            }
        }

        while(!FIRE_Q.empty()){
            auto pos = FIRE_Q.front(); FIRE_Q.pop();

            for(int k=0; k < 4; k++){
                int mx = pos.X + dx[k];
                int my = pos.Y + dy[k];

                if(mx < 0 || my < 0 || mx >= n || my>= m) continue;
                if(vit[mx][my] > 0 || board[mx][my] == -1) continue;

                vit[mx][my] = vit[pos.X][pos.Y] + 1;
                FIRE_Q.push({mx,my});
            }
        }

        while(!MAN_Q.empty()){
            auto pos = MAN_Q.front(); MAN_Q.pop();
            if(pos.X == 0 || pos.X == n-1 || pos.Y == 0 || pos.Y == m-1){
                result = vit2[pos.X][pos.Y];
                break;
            }

            for(int k=0; k < 4; k++){
                int mx = pos.X + dx[k];
                int my = pos.Y + dy[k];

                if(mx < 0 || my < 0 || mx >= n || my>= m) continue;
                if(vit2[mx][my] > 0 || board[mx][my] == -1) continue;

                vit2[mx][my] = vit2[pos.X][pos.Y] + 1;
                if(vit[mx][my] == 0 || vit2[mx][my] < vit[mx][my]){
                    MAN_Q.push({mx,my});
                }
            }
        }
        
        if(result == 0) cout << "IMPOSSIBLE\n";
        else cout << result << "\n";
    }
}
