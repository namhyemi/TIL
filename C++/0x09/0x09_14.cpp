// https://www.acmicpc.net/problem/2146
// 2146��. �ٸ� �����

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[105][105]; // �Է¹迭
int vit[105][105];
int dis[105][105];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> Q;
    int cnt = 0;
    for(int i=0; i < n; i++){ // �� ����
        for(int j=0; j < n; j++){
            if(vit[i][j] == 0 && board[i][j] == 1){
                cnt++;
                vit[i][j] = cnt;
                Q.push({i,j});
            }

            while(!Q.empty()){
                auto pos = Q.front(); Q.pop();

                for(int k=0; k < 4; k++){
                    int mx = pos.X + dx[k];
                    int my = pos.Y + dy[k];

                    if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                    if(vit[mx][my] != 0 || board[mx][my] == 0) continue;

                    vit[mx][my] = cnt;
                    Q.push({mx, my});
                }
            }
            
        }
    }

    int min_cnt = 100;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
           if(vit[i][j] != 0){
            dis[i][j] = 1;
            Q.push({i,j});

                while(!Q.empty()){
                    auto pos = Q.front(); Q.pop();

                    for(int k=0; k < 4; k++){
                        int mx = pos.X + dx[k];
                        int my = pos.Y + dy[k];

                        if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                        if(dis[mx][my] > 0 || vit[i][j] == vit[mx][my]) continue; // ���� ������ üũ
                        if(vit[mx][my] != 0 && vit[i][j] != vit[mx][my]){ // �ٸ� ���� ���
                            min_cnt = min(min_cnt, dis[pos.X][pos.Y]); 
                            while(!Q.empty()) Q.pop(); // �ش� ĭ ����
                            break;
                        }
                        dis[mx][my] = dis[pos.X][pos.Y] + 1;
                        Q.push({mx,my});
                    }
                }
            fill(&dis[0][0], &dis[n][n], 0); //�Ÿ� üũ �ʱ�ȭ
            }
        }
    }
    cout << min_cnt-1;
}
