// https://www.acmicpc.net/problem/7576
// 7576��. �丶��

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
    fill(&vit[0][0], &vit[n][m], -1); // �湮 �迭 -1���� �ʱ�ȭ
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){ // ���� �丶��� ť�� ���, �湮 �迭�� 0���� �ٲٱ�
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
            if(box[i][j] != -1 && vit[i][j] == -1){ // ������� ������ �湮�� ���� ������ -1
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << max_cnt << "\n";
}


// �Ǽ�(*) : || ����ϴµ� && �߸� ���
// �Ǽ�(*) : ��ȣ(=) �ϳ� ����ϴµ� �ΰ�(==) ���
// �Ǽ� : �Է¿��� ���Ǵ� ��� �� ���Ǳ�� ����.


// Ʋ�� ���� : �̹� ��� �;��ִ� ��쿡 -1�� ��µ�.(if ���� ���� �����ε� �߰�ȣ ��� ����)
// Ʋ�� ���� : ��� �;��ִ� ��� ó�� �ȵ�.