// https://www.acmicpc.net/problem/4179
// 4179��. ��

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

// �������� ����� 0���� �ʱ�ȭ
int maze[1005][1005]; // �̷� ��
int fire_min[1005][1005]; // �� �̵� ��ο� ���� �ð�
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
            if(str[j] == '#') maze[i][j] = -1; // ��
            else if(str[j] == 'J'){
                JH.push({i,j}); // ���� ��ġ
                jh_min[i][j] = 1;
            }
            else if(str[j] == 'F'){  // �� ��ġ
                Fire.push({i,j});
                fire_min[i][j] = 1;
            }
            else ; 
        }
    }

    pair<int,int> pos; 
    while(!Fire.empty()){ // �� �̵�
        pos = Fire.front(); Fire.pop();

        for(int k=0; k < 4; k++){
            int move_x = pos.X + dx[k];
            int move_y = pos.Y + dy[k];

            if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m) continue; // ���� ������� üũ
            if(maze[move_x][move_y] == -1 || fire_min[move_x][move_y] > 0) continue; // ������ �鸰���ִ��� üũ

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


    while(!JH.empty()){ // ���� �̵� (�� �̵� �ð��� ��Ұ� ��ġ����)
        pos = JH.front(); JH.pop();

        for(int k=0; k < 4; k++){
            int move_x = pos.X + dx[k];
            int move_y = pos.Y + dy[k];

            if(move_x < 0 || move_y < 0 || move_x >= n || move_y >= m){  // ���� ��ġ�� �����ڸ��� Ż��
                // cout << pos.X << " " << pos.Y << "\n";
                cout << jh_min[pos.X][pos.Y] << "\n";
                return 0;;
            }
            if(maze[move_x][move_y] == -1 || jh_min[move_x][move_y] > 0) continue; // ������ �鸰���ִ��� üũ

            jh_min[move_x][move_y] = jh_min[pos.X][pos.Y] + 1;
            if(fire_min[move_x][move_y] == 0 || jh_min[move_x][move_y] < fire_min[move_x][move_y]){ //���� ���� ������ ���������� üũ
                JH.push({move_x, move_y});
            }
        } 
    }
    cout << "IMPOSSIBLE";
}

// Ʋ�� ���� : Ż�� ���� ��� ó�� ����.
// Ʋ�� ���� : ���� ���� ��� ó�� ����.