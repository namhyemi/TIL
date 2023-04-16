// https://www.acmicpc.net/problem/15686
// 15686번. 치킨 배달

/* 
1. 지도를 2차원 배열(board)로 입렵받는다. (+ 치킨 위치 배열(store_arr) / 집 위치 배열(house_arr))
2. 치킨가게 마다 BFS 돌린다.
3. 각 치킨가게 거리 계산 값을 저장한다. (store_vis[i])
4. 치킨가게 조합 선별한다.
5. 각 집마다 선별된 치킨집 거리 중 제일 작은 거리를 더한다.
6. 모든 조합중에 가장 짧은 거리를 출력한다.
*/

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board_size, choose_store_num;
int board[55][55];
int store_vis[13][55][55]; // 가게(최대 13개) 마다 집까지 거리 배열
int min_sum_dis = 100000;

vector<int> choose_store; // 조합
vector<pair<int,int>> house_arr; // 집 배열
vector<pair<int,int>> store_arr; // 가게 배열

void InputUserData(){
    cin >> board_size >> choose_store_num;

    for(int i=0; i < board_size; i++){
        for(int j=0; j < board_size; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){ house_arr.push_back({i,j}); } // 집 위치
            if(board[i][j] == 2){ store_arr.push_back({i,j}); } // 가게 위치
        }
    }
}

void CalDistanceFromStore(){ // BFS
    for(int i=0; i < store_arr.size(); i++){
        fill(&store_vis[i][0][0], &store_vis[i][board_size][board_size], -1); // 방문 배열 초기화
        queue<pair<int,int>> Q;
        Q.push({store_arr[i].X, store_arr[i].Y}); // 가게 위치 하나 선정

        store_vis[i][store_arr[i].X][store_arr[i].Y] = 0;
        while(!Q.empty()){
            auto pos = Q.front(); Q.pop();
            for(int k=0; k<4; k++){
                int mx = pos.X + dx[k];
                int my = pos.Y + dy[k];

                if(mx < 0 || my < 0 || mx >= board_size || my >= board_size) continue; // 유효 범위 확인
                if(store_vis[i][mx][my] != -1) continue; // 방문 여부 확인

                store_vis[i][mx][my] = store_vis[i][pos.X][pos.Y] + 1;
                Q.push({mx,my});
            }
        }
    }
}

void CalMinDistance(){
    int sum_dis = 0;
    for(int i = 0; i < house_arr.size(); i++){ // 집마다
        int min_dis = 100000;
        for(int j=0; j < store_arr.size(); j++){
            if(choose_store[j] == 0){ // 선택된 치킨집까지의 거리(store_vis[j][house_arr[i].X][house_arr[i].Y])
                // cout << j << "거리 :" << store_vis[j][house_arr[i].X][house_arr[i].Y] << "\n";
                min_dis = min(min_dis, store_vis[j][house_arr[i].X][house_arr[i].Y]); // 각 집마다 가장 짧은 치킨집 확인하기 
            }
        } sum_dis += min_dis;
    }
    min_sum_dis = min(min_sum_dis, sum_dis);
}

void ChooseStore(){ // 조합
    for(int i=0; i<store_arr.size(); i++) choose_store.push_back(i < choose_store_num ? 0 : 1);
    do{
        CalMinDistance();
    }while(next_permutation(choose_store.begin(),choose_store.end()));
}


void OutputResult(){
    cout << min_sum_dis << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    CalDistanceFromStore();
    ChooseStore();
    OutputResult();
}

