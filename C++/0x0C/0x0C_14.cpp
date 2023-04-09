// https://www.acmicpc.net/problem/1941
// 1941번. 소문난 칠공주

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
            if(vis[mx][my] != 1) continue; // vis가 1이면 결성 멤버 (0이면 제외 인원, 2면 이미 확인 멤버)

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
            if(!result_board[i][j]){ // 중복 방지
                if(board[i][j] == 'Y') Y_cnt++;
                if(Y_cnt > 3){ // 조건 : 'S' 4명 이상 / 'Y' 3명 이하
                    Y_cnt--;
                    continue;
                }
                if(n==0){ // 처음 결성된 사람 위치 저장 (BFS)
                    start_X = i;
                    start_Y = j;
                }
                result_board[i][j] = 1; // 팀 참여
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

// 틀린 이유 : ??


// 실수 : 중간 결과 확인 코드 제거 안하고 제출
        // for(int i=0; i<5; i++){
        //     for(int j=0; j<5; j++){
        //         if(result_board[i][j]) 
        //             cout << board[i][j];
        //         else cout << ".";
        //     } cout << "\n";
        // } cout << "\n";

// 틀린 이유 : 이전 뽑은 사람의 다음 자리부터 접근하는 방법 고민 -> 함수에 현재 위치값 넘김 (check_i, check_j)
// 틀린 이유 : 뒤에서 부터 연결되는 경우 제외 -> 자리가 붙어있는지 맨 마지막에 검사
// 틀린 이유 : 붙어있는 여부 확인 방법 

/*
// 수정 전 임시 저장
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
            if(!result_board[i][j]){ // 중복 방지
                if(n == 0) ; // 처음 뽑힐때는 인접한 사람 없음
                else if(i > 0 && result_board[i-1][j]) ; // 조건 : 세로로 인접한 사람 확인
                else if(j > 0 && result_board[i][j-1]) ; // 조건 : 가로로 인접한 사람 확인
                else continue;

                if(board[i][j] == 'Y') Y_cnt++;
                if(Y_cnt > 3){ // 조건 : 'S' 4명 이상
                    Y_cnt--;
                    continue;
                }

                result_board[i][j] = 1; // 사용 
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
            if(!result_board[i][j]){ // 중복 방지
                if(board[i][j] == 'Y') Y_cnt++;
                if(Y_cnt > 3){ // 조건 : 'S' 4명 이상
                    Y_cnt--;
                    continue;
                }

                result_board[i][j] = 1; // 사용 
                func(n+1, i, j);
                result_board[i][j] = 0;
                if(board[i][j] == 'Y') Y_cnt--;
            }
        }
    }
}

*/