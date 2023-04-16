// https://www.acmicpc.net/problem/15686
// 15686��. ġŲ ���

/* 
1. ������ 2���� �迭(board)�� �Էƹ޴´�. (+ ġŲ ��ġ �迭(store_arr) / �� ��ġ �迭(house_arr))
2. ġŲ���� ���� BFS ������.
3. �� ġŲ���� �Ÿ� ��� ���� �����Ѵ�. (store_vis[i])
4. ġŲ���� ���� �����Ѵ�.
5. �� ������ ������ ġŲ�� �Ÿ� �� ���� ���� �Ÿ��� ���Ѵ�.
6. ��� �����߿� ���� ª�� �Ÿ��� ����Ѵ�.
*/

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board_size, choose_store_num;
int board[55][55];
int store_vis[13][55][55]; // ����(�ִ� 13��) ���� ������ �Ÿ� �迭
int min_sum_dis = 100000;

vector<int> choose_store; // ����
vector<pair<int,int>> house_arr; // �� �迭
vector<pair<int,int>> store_arr; // ���� �迭

void InputUserData(){
    cin >> board_size >> choose_store_num;

    for(int i=0; i < board_size; i++){
        for(int j=0; j < board_size; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){ house_arr.push_back({i,j}); } // �� ��ġ
            if(board[i][j] == 2){ store_arr.push_back({i,j}); } // ���� ��ġ
        }
    }
}

void CalDistanceFromStore(){ // BFS
    for(int i=0; i < store_arr.size(); i++){
        fill(&store_vis[i][0][0], &store_vis[i][board_size][board_size], -1); // �湮 �迭 �ʱ�ȭ
        queue<pair<int,int>> Q;
        Q.push({store_arr[i].X, store_arr[i].Y}); // ���� ��ġ �ϳ� ����

        store_vis[i][store_arr[i].X][store_arr[i].Y] = 0;
        while(!Q.empty()){
            auto pos = Q.front(); Q.pop();
            for(int k=0; k<4; k++){
                int mx = pos.X + dx[k];
                int my = pos.Y + dy[k];

                if(mx < 0 || my < 0 || mx >= board_size || my >= board_size) continue; // ��ȿ ���� Ȯ��
                if(store_vis[i][mx][my] != -1) continue; // �湮 ���� Ȯ��

                store_vis[i][mx][my] = store_vis[i][pos.X][pos.Y] + 1;
                Q.push({mx,my});
            }
        }
    }
}

void CalMinDistance(){
    int sum_dis = 0;
    for(int i = 0; i < house_arr.size(); i++){ // ������
        int min_dis = 100000;
        for(int j=0; j < store_arr.size(); j++){
            if(choose_store[j] == 0){ // ���õ� ġŲ�������� �Ÿ�(store_vis[j][house_arr[i].X][house_arr[i].Y])
                // cout << j << "�Ÿ� :" << store_vis[j][house_arr[i].X][house_arr[i].Y] << "\n";
                min_dis = min(min_dis, store_vis[j][house_arr[i].X][house_arr[i].Y]); // �� ������ ���� ª�� ġŲ�� Ȯ���ϱ� 
            }
        } sum_dis += min_dis;
    }
    min_sum_dis = min(min_sum_dis, sum_dis);
}

void ChooseStore(){ // ����
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

