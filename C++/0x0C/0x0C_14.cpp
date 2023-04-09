// https://www.acmicpc.net/problem/1941
// 1941��. �ҹ��� ĥ����

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int start_X = 0, start_Y = 0;
int Y_cnt = 0;
int result_cnt = 0;
int result_board[5][5];
int vis[5][5];

string board[5];

int BFS(){
    int sum = 1;
    queue<pair<int,int>> Q;

    vis[start_X][start_Y]++;
    Q.push({start_X, start_Y});
    
    while(!Q.empty()){
        auto pos = Q.front(); Q.pop();

        for(int i=0; i<4; i++){
            int mx = pos.X + dx[i];
            int my = pos.Y + dy[i];

            if(mx < 0 || my < 0 || mx >= 5 || my >= 5) continue;
            if(vis[mx][my] != 1) continue; // vis�� 1�̸� �Ἲ ��� (0�̸� ���� �ο�, 2�� �̹� Ȯ�� ���)

            sum++;
            vis[mx][my]++;
            Q.push({mx,my});
        }
    }
    return sum;
}

void func(int n, int check_i, int check_j){
    if(n==7){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                vis[i][j] == result_board[i][j];
            }
        }
        if(BFS() == 7) result_cnt++;
        return;
    }

    for(int i=check_i; i<5; i++){
        if(i != check_i) check_j = 0;
        for(int j=check_j; j<5; j++){
            if(!result_board[i][j]){ // �ߺ� ����
                if(board[i][j] == 'Y') Y_cnt++;
                if(Y_cnt > 3){ // ���� : 'S' 4�� �̻� / 'Y' 3�� ����
                    Y_cnt--;
                    continue;
                }
                if(n==0){ // ó�� �Ἲ�� ��� ��ġ ���� (BFS)
                    start_X = i;
                    start_Y = j;
                }
                result_board[i][j] = 1; // �� ����
                func(n+1, i, j);
                result_board[i][j] = 0;
                if(board[i][j] == 'Y') Y_cnt--;
            }
        }
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++)  cin >> board[i];

    func(0, 0, 0);

    cout << result_cnt;
}

// Ʋ�� ���� : ??


// �Ǽ� : �߰� ��� Ȯ�� �ڵ� ���� ���ϰ� ����
        // for(int i=0; i<5; i++){
        //     for(int j=0; j<5; j++){
        //         if(result_board[i][j]) 
        //             cout << board[i][j];
        //         else cout << ".";
        //     } cout << "\n";
        // } cout << "\n";

// Ʋ�� ���� : ���� ���� ����� ���� �ڸ����� �����ϴ� ��� ��� -> �Լ��� ���� ��ġ�� �ѱ� (check_i, check_j)
// Ʋ�� ���� : �ڿ��� ���� ����Ǵ� ��� ���� -> �ڸ��� �پ��ִ��� �� �������� �˻�
// Ʋ�� ���� : �پ��ִ� ���� Ȯ�� ��� 

/*
// ���� �� �ӽ� ����
#include<bits/stdc++.h>

using namespace std;

int Y_cnt = 0;
int result_cnt = 0;
int result_board[5][5];
string board[5];

void func(int n, int check_i, int check_j){
    if(n==7){
        result_cnt++;
        return;
    }

    for(int i=check_i; i<5; i++){
        if(i != check_i) check_j = 0;
        for(int j=check_j; j<5; j++){
            if(!result_board[i][j]){ // �ߺ� ����
                if(n == 0) ; // ó�� �������� ������ ��� ����
                else if(i > 0 && result_board[i-1][j]) ; // ���� : ���η� ������ ��� Ȯ��
                else if(j > 0 && result_board[i][j-1]) ; // ���� : ���η� ������ ��� Ȯ��
                else continue;

                if(board[i][j] == 'Y') Y_cnt++;
                if(Y_cnt > 3){ // ���� : 'S' 4�� �̻�
                    Y_cnt--;
                    continue;
                }

                result_board[i][j] = 1; // ��� 
                func(n+1, i, j);
                result_board[i][j] = 0;
                if(board[i][j] == 'Y') Y_cnt--;
            }
        }
    }
}
*/



/*
void func(int n, int check_i, int check_j){
    if(n==7){
        int sum = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(result_board[i][j]){
                    if(i > 0 && result_board[i-1][j]) ;
                    else if(j > 0 && result_board[i][j-1]) ;
                    else if(i < 4 && result_board[i+1][j]) ;
                    else if(j < 4 && result_board[i][j+1]) ;
                    else continue;
                    sum++;
                }       
            }
        }
        if(sum==7) result_cnt++;
        return;
    }

    for(int i=check_i; i<5; i++){
        if(i != check_i) check_j = 0;
        for(int j=check_j; j<5; j++){
            if(!result_board[i][j]){ // �ߺ� ����
                if(board[i][j] == 'Y') Y_cnt++;
                if(Y_cnt > 3){ // ���� : 'S' 4�� �̻�
                    Y_cnt--;
                    continue;
                }

                result_board[i][j] = 1; // ��� 
                func(n+1, i, j);
                result_board[i][j] = 0;
                if(board[i][j] == 'Y') Y_cnt--;
            }
        }
    }
}

*/