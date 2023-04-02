// https://www.acmicpc.net/problem/2573
// 2573��. ����

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[305][305]; // �Է� �迭
int vit[305][305]; 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;

void BFS(){
    int year = 0;
    queue<pair<int,int>> Q;

    while(true){
        int cnt = 0;
        fill(&vit[0][0], &vit[n][m], 0);
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(vit[i][j] == 0 && board[i][j] > 0){ // �湮���� ���� ����ĭ
                    vit[i][j] = 1;
                    Q.push({i, j});
                    cnt++;

                    while(!Q.empty()){
                        auto pos = Q.front(); Q.pop();
                        for(int k=0; k < 4; k++){ // ����ĭ Ȯ��
                            int mx = pos.X + dx[k];
                            int my = pos.Y + dy[k];

                            if(mx < 0 || my < 0 || mx >= n || my >= m) continue; // ������ ��ȿ���� Ȯ��

                            if(vit[mx][my] == 0){
                                if(board[mx][my] <= 0){ // �ٴ��� ���
                                    if(board[pos.X][pos.Y] - 1 >= 0){
                                        board[pos.X][pos.Y] -= 1;
                                    }
                                }
                                if(board[mx][my] > 0){ // ������ ���
                                    vit[mx][my] = 1;
                                    Q.push({mx,my});
                                }
                            }
                        }
                    }
                }
            }
        }
        year++;
        if(cnt >= 2){ // ���� ������ �ΰ��� ��� 
            cout << year-1 << "\n";
            break;
        }
        if(cnt == 0){ // ������ ��� ���� ���
            cout << cnt << "\n"; 
            break;
        }
    }
}

int UserInputData(){
    int cnt = 0;
    for(int i=0; i<n; i++){ // �Է� �ޱ�
        for(int j=0; j< m; j++){
            cin >> board[i][j];
            if(board[i][j] != 0) cnt++;
        }
    }   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = UserInputData();

    if(cnt == n*m) cout << 0 << "\n"; // ��ü�� ������ ���
    else BFS();
}

// Ʋ�� ���� : �ð� �ʰ�