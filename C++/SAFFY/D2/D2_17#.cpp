// 1954

#include<bits/stdc++.h>

using namespace std;

int table_arr[15][15];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int num;
        cin >> num;

        memset(table_arr, 0, sizeof(table_arr));

        int dir = 0;
        int mv_x = 0, mv_y = 0;

        for(int i = 1; i <= num * num; i++){
            table_arr[mv_x][mv_y] = i;
            if(mv_x + dx[dir] >= num || mv_x + dx[dir] < 0 || mv_y + dy[dir] >= num || mv_y + dy[dir] < 0 || table_arr[mv_x + dx[dir]][mv_y + dy[dir]] != 0){
                dir = (dir + 1) % 4;
            }
            mv_x += dx[dir];
            mv_y += dy[dir];
        }

        cout << "#" << test_case << "\n";
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                cout << table_arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
