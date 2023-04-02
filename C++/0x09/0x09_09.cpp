// https://www.acmicpc.net/problem/2468
// 2468번. 안전 영역

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[105][105];
int vit[105][105];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, max_h=0;
    cin >> n;

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]);
        }
    }

    int max_area = 1; // 최대 영역

    queue<pair<int,int>> Q;
    for(int w=1; w < max_h; w++){ // 비 내린 높이마다 체크
        fill(&vit[0][0], &vit[n][n], 0); // 방문 기록 초기화
        int cnt=0; 
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if(vit[i][j] == 0 && board[i][j] > w){
                    vit[i][j] = 1;
                    Q.push({i,j});
                    cnt++;
                }

                while(!Q.empty()){
                    auto pos = Q.front(); Q.pop();

                    for(int k=0; k < 4; k++){
                        int mx = pos.X + dx[k];
                        int my = pos.Y + dy[k];

                        if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                        if(vit[mx][my] != 0 || board[mx][my] <= w) continue;

                        vit[mx][my] = 1;
                        Q.push({mx,my});
                    }
                }
            }
        }
        max_area = max(max_area, cnt);
    }
    cout << max_area << "\n";
}
