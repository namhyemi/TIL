// https://www.acmicpc.net/problem/4179
// 4179번. 불

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

// 전역변수 선언시 0으로 초기화
int maze[1005][1005]; // 미로 벽
int fire_min[1005][1005]; // 불 이동 경로에 따른 시간
int jh_min[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n, m;
    cin >> n >> m;

    string str;
     
    queue<pair<int,int>> Fire, JH;

    for(int i=0; i < n; i++){
        cin >> str;
        for(int j=0; j < m; j++){
            if(str[j] == '#') maze[i][j] = -1; // 벽
            else if(str[j] == 'J'){
                JH.push({i,j}); // 지훈 위치
                jh_min[i][j] = 1;
            }
            else if(str[j] == 'F'){  // 불 위치
                Fire.push({i,j});
                fire_min[i][j] = 1;
            }
            else ; 
        }
    }

    pair<int,int> pos; 
    while(!Fire.empty()){ // 불 이동
        pos = Fire.front(); Fire.pop();

        for(int k=0; k < 4; k++){
            int move_x = pos.X + dx[k];
            int move_y = pos.Y + dy[k];

            if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m) continue; // 범위 벗어나는지 체크
            if(maze[move_x][move_y] == -1 || fire_min[move_x][move_y] > 0) continue; // 벽인지 들린적있는지 체크

            fire_min[move_x][move_y] = fire_min[pos.X][pos.Y] + 1;
            Fire.push({move_x, move_y});
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << fire_min[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    while(!JH.empty()){ // 지훈 이동 (불 이동 시간대 장소가 겹치는지)
        pos = JH.front(); JH.pop();

        for(int k=0; k < 4; k++){
            int move_x = pos.X + dx[k];
            int move_y = pos.Y + dy[k];

            if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m){  // 지훈 위치가 가장자리면 탈출
                // cout << pos.X << " " << pos.Y << "\n";
                cout << jh_min[pos.X][pos.Y] << "\n";
                return 0;;
            }
            if(maze[move_x][move_y] == -1 || jh_min[move_x][move_y] > 0) continue; // 벽인지 들린적있는지 체크

            jh_min[move_x][move_y] = jh_min[pos.X][pos.Y] + 1;
            if(fire_min[move_x][move_y] == 0 || jh_min[move_x][move_y] < fire_min[move_x][move_y]){ //불이 아직 번지지 않은곳인지 체크
                JH.push({move_x, move_y});
            }
        } 
    }
    cout << "IMPOSSIBLE";
}

// 틀린 이유 : 탈출 실패 경우 처리 안함.
// 틀린 이유 : 불이 없는 경우 처리 안함.