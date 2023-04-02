// https://www.acmicpc.net/problem/7569
// 7569번. 토마토

#include<bits/stdc++.h>

using namespace std;

int board[105][105][105];
int vit[105][105][105];

int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int,int,int>> Q;
    int n, m, l;
    cin >> m >> n >> l;

    fill(&vit[0][0][0], &vit[n][m][l], -1); // 방문 배열 초기화
    for(int i=0; i < n; i++){ // 3차원 배열 초기화
        for(int j=0; j < m; j++){
            for(int k=0; k < l; k++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){ // 익은 토마토 큐에 담기
                    Q.push({i,j,k});
                    vit[i][j][k] = 0;
                }
            }
        }
    }    
    int x, y, z, max_cnt=0;
    while(!Q.empty()){
        tie(x, y, z) = Q.front(); Q.pop();

        for(int i=0; i < 6; i++){
            int mx = x + dx[i];
            int my = y + dy[i];
            int mz = z + dz[i];

            if(mx < 0 || my < 0 || mz < 0 || mx >= n || my >= m || mz >= l) continue;
            if(vit[mx][my][mz] >= 0 || board[mx][my][mz] == -1) continue; // 비어있거나 이미 익은 경우  

            vit[mx][my][mz] = vit[x][y][z] + 1;
            Q.push({mx,my,mz});
            max_cnt = max(vit[mx][my][mz], max_cnt);
            cout << mx << " " << my << " " << mz << " " << max_cnt << "\n";
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<l; k++){
                if(board[i][j][k] != -1 && vit[i][j][k] == -1){ // 비어있지 않은데 방문한 적이 없으면 -1
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << max_cnt << "\n";
}

// 틀린 이유 : ?? (3차원 배열 순서?)