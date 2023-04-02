// https://www.acmicpc.net/problem/2178
// 2178번. 미로 탐색

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int maze[100][100];
int cnt[100][100];
int vit[100][100] = {0};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n,m;
    cin >> n >> m;

    fill(&cnt[0][0], &cnt[n][m], 10001);

    for(int i=0; i < n ; i++){ // 미로 입력값 담기
        cin >> str;
        for(int j=0; j < m; j++){
            maze[i][j] = str[j] - '0';
        }
    }

    queue<pair<int,int>> Q;
    pair<int, int> pos;
    
    Q.push({0,0});
    vit[0][0] = 1;
    cnt[0][0] = 1;

    while(!Q.empty()){
        pos = Q.front(); 
        Q.pop();
 
        for(int k=0; k < 4; k++){
            int move_x = pos.X + dx[k];
            int move_y = pos.Y + dy[k];

            if(move_x < 0 || move_x >= n || move_y < 0 || move_y >= m) continue;
            if(vit[move_x][move_y] == 1 || maze[move_x][move_y] == 0) continue;
            vit[move_x][move_y] = 1;
            Q.push({move_x,move_y});
            

            if(cnt[move_x][move_y] > cnt[pos.X][pos.Y]+1) // 다른 곳을 통해서 들렸을때보다 값이 작다면
            /// 필요 없는 과정. 어차피 이미 거친적이 있다면 들어있는 값이 최소값임.
                cnt[move_x][move_y] = cnt[pos.X][pos.Y]+1; 
        }       
    }
    cout << cnt[n-1][m-1] << "\n";
}

// 실수 : || 써야하는데 && 잘못 사용.


/// 필요 없는 과정을 뺀 코드
// #include <bits/stdc++.h>
// using namespace std;
// #define X first
// #define Y second
// string board[102];
// int dist[102][102];
// int n,m;
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> m;
//   for(int i = 0; i < n; i++)
//     cin >> board[i];
//   for(int i = 0; i < n; i++) fill(dist[i],dist[i]+m,-1);
//   queue<pair<int,int> > Q;
//   Q.push({0,0});
//   dist[0][0] = 0;
//   while(!Q.empty()){
//     auto cur = Q.front(); Q.pop();
//     for(int dir = 0; dir < 4; dir++){
//       int nx = cur.X + dx[dir];
//       int ny = cur.Y + dy[dir];
//       if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//       if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
//       dist[nx][ny] = dist[cur.X][cur.Y]+1;
//       Q.push({nx,ny});
//     }
//   }
//   cout << dist[n-1][m-1]+1; // 문제의 특성상 거리+1이 정답
// }