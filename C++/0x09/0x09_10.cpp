// https://www.acmicpc.net/problem/6593
// 6593번. 상범 빌딩

#include<bits/stdc++.h>

using namespace std;

string board[35][35];
int vit[35][35][35];

int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        queue<tuple<int,int,int>> Q;
        tuple<int,int,int> Escape;
        int L, R, C;
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;

        fill(&vit[0][0][0], &vit[L][R][C], 0); // 방문기록 초기화

        for(int i=0; i < L; i++){ // 3차원 배열 초기화
            for(int j=0; j < R; j++){
                cin >> board[i][j];
                for(int k=0; k < C; k++){
                    if(board[i][j][k] == 'S'){ // 출발 위치
                        vit[i][j][k] = 1;
                        Q.push({i,j,k});
                    }
                }
            }
        }

        bool isValue = 0;
        while(!Q.empty()){
            auto pos = Q.front(); Q.pop();
            if(board[get<0>(pos)][get<1>(pos)][get<2>(pos)] == 'E'){
                cout << "Escaped in " << vit[get<0>(pos)][get<1>(pos)][get<2>(pos)]-1 << " minute(s).\n";
                isValue = 1;
                break;
            }

            for(int i=0; i < 6; i++){
                int mx = get<0>(pos) + dx[i];
                int my = get<1>(pos) + dy[i];
                int mz = get<2>(pos) + dz[i];

                if(mx < 0 || my < 0 || mz < 0 || mx >= L || my >= R || mz >= C) continue;
                if(vit[mx][my][mz] != 0 || board[mx][my][mz] == '#') continue;

                vit[mx][my][mz] = vit[get<0>(pos)][get<1>(pos)][get<2>(pos)] + 1;
                Q.push({mx,my,mz});
            }
        }
        if(!isValue) cout << "Trapped!\n";
    }
}

// tuple 공부

// 틀린 이유 : 방문기록 초기화