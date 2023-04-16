// https://www.acmicpc.net/problem/15686
// 15686��. ġŲ ���

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board_size, final_store_num;
int board[55][55];
int vis[55][55];
int house_vis[105];
int min_sum = 3000;

vector<pair<int,int>> house_arr;
vector<pair<int,int>> store_arr;
vector<int> use_store;

void InputUserData(){
    cin >> board_size >> final_store_num;

    for(int i=0; i<board_size; i++){
        for(int j=0; j<board_size; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){ house_arr.push_back({i,j}); } // �� ��ġ
            if(board[i][j] == 2){ store_arr.push_back({i,j}); } // ���� ��ġ
        }
    }
}

// void OutputUserData(){
//     for(int i=0; i<board_size; i++){
//         cout << "\n";
//         for(int j=0; j<board_size; j++){
//             cout << board[i][j] << " ";
//         }
//     }
// }

void ResetArr(int i){
    fill(house_vis, house_vis+house_arr.size(), 0);
    fill(&vis[0][0], &vis[board_size][board_size], 0); // �湮 ��� �ʱ�ȭ
    vis[house_arr[i].X][house_arr[i].Y] = 1;
}

void CheckDistance(){ // BFS
    int sum = 0;
    for(int i = 0; i < house_arr.size(); i++){ // �� �⸶�� �ѹ��� üũ
        ResetArr(i);
        queue<pair<int,int>> Q;
        
        Q.push({house_arr[i].X, house_arr[i].Y}); 
        while(!Q.empty()){
            if(house_vis[i] != 0) { break;} // ġŲ�� �湮�� �ش� �� ����
            auto person = Q.front(); Q.pop();
            for(int k=0; k<4; k++){
                int mx = person.X + dx[k];
                int my = person.Y + dy[k];

                if(mx < 0 || my < 0 || mx >= board_size || my >= board_size) continue; // ���� ����� ���
                if(vis[mx][my] != 0) continue; // �湮�� �� �ִ� ���

                vis[mx][my] = vis[person.X][person.Y]+1;
                Q.push({mx,my});
                if(board[mx][my] == 2){ // ġŲ�� �湮�� �ش� �� ����
                    house_vis[i] = vis[person.X][person.Y];
                    sum += vis[person.X][person.Y]; // �Ÿ� �ջ�
                }
            }
        }
    }
    min_sum = min(min_sum, sum);
}

void ChangeBoard(){ // ���õ� ġŲ���� ���ܵα�
    for(int i=0; i<store_arr.size(); i++){
        if(use_store[i] == 0) board[store_arr[i].X][store_arr[i].Y] = 2;
        else if(use_store[i] == 1) board[store_arr[i].X][store_arr[i].Y] = 0;
    }
}

void ChooseStore(){ // ���� ����(��)
    for(int i=0; i<store_arr.size(); i++) use_store.push_back(i < final_store_num ? 0 : 1); // ex.���� 5���� 3�� ���ý� [0, 0, 0, 1, 1]
    do{
        ChangeBoard();
        CheckDistance();
    } while(next_permutation(use_store.begin(), use_store.end()));
}

void OutputResult(){
    cout << min_sum << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    ChooseStore();
    OutputResult();
}

// Ʋ�� ���� : �ð� �ʰ�