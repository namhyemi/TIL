// https://www.acmicpc.net/problem/7576
// 7576번. 토마토

#include<bits/stdc++.h>

#define X first 
#define Y second

using namespace std;

int box[1005][1005];
int vit[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;
    int n, m;
    cin >> m >> n;
    fill(&vit[0][0], &vit[n][m], -1); // 방문 배열 -1으로 초기화
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){ // 익은 토마토는 큐에 담고, 방문 배열을 0으로 바꾸기
                Q.push({i,j});
                vit[i][j] = 0;
            }
        }
    }

    int max_cnt = 0;
    while(!Q.empty()){
        pair<int,int> pos = Q.front(); Q.pop();

        for(int k=0; k < 4; k++){
            int move_x = pos.X + dx[k];
            int move_y = pos.Y + dy[k];
            
            if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m) continue;
            if(box[move_x][move_y] == -1 || vit[move_x][move_y] >= 0) continue;
            
            vit[move_x][move_y] = vit[pos.X][pos.Y] + 1;
            Q.push({move_x,move_y});
            max_cnt = max(vit[move_x][move_y], max_cnt);
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(box[i][j] != -1 && vit[i][j] == -1){ // 비어있지 않은데 방문한 적이 없으면 -1
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << max_cnt << "\n";
}


// 실수(*) : || 써야하는데 && 잘못 사용
// 실수(*) : 등호(=) 하나 써야하는데 두개(==) 사용
// 실수 : 입력에서 사용되는 행과 열 주의깊게 보기.


// 틀린 이유 : 이미 모두 익어있는 경우에 -1이 출력됨.(if 문에 문장 두줄인데 중괄호 사용 안함)
// 틀린 이유 : 모두 익어있는 경우 처리 안됨.