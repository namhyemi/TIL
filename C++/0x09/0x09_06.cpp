// https://www.acmicpc.net/problem/5427
// 5427น๘. บา

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[105][105];
int vit[105][105];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> area;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w, num;
    cin >> h >> w >> num; 

    while(num--){
        pair<int,int> start, end;
        cin >> start.Y >> start.X >> end.Y >> end.X;
        
        for(int i=start.X; i < end.X; i++){
            for(int j=start.Y; j < end.Y; j++){
                if(board[i][j] == 0) board[i][j] = -1;
            }
        }
    }

    queue<pair<int,int>> Q;

    for(int i=0; i < h; i++){
        for(int j=0; j < w; j++){
            int cnt = 0;
            if(board[i][j] == 0 && vit[i][j] == 0){
                vit[i][j] = 1;
                Q.push({i,j});
                cnt++;
            }

            while(!Q.empty()){
                auto pos = Q.front(); Q.pop();
                
                for(int k=0; k < 4; k++){
                    int mx = pos.X + dx[k];
                    int my = pos.Y + dy[k];

                    if(mx < 0 || my < 0 || mx >= h || my >= w) continue;
                    if(vit[mx][my] > 0 || board[mx][my] == -1) continue;
                    vit[mx][my] = 1;
                    Q.push({mx,my});
                    cnt++;
                }
            }
            if(cnt != 0) area.push_back(cnt);
        }
    }
    sort(area.begin(), area.end());

    cout << area.size() << "\n";
    for(int i=0; i < area.size(); i++){
        cout << area[i] << " ";
    }
    cout << "\n";
}
