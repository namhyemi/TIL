// https://www.acmicpc.net/problem/1780
// 1780번. 종이의 개수

#include<bits/stdc++.h>

using namespace std;

int board[2200][2200];
int numarr[3] = {0};

void CutPaper(int a, int b, int n){
    // base condition
    if(n==3){
        int cnt = 0;
        bool checkPoint = false;
        for(int i=a; i < a+n; i++){ 
            for(int j=b; j < b+n; j++){
                if(checkPoint == 0) 
                    if(board[a][b] != board[i][j]){ // 한번이라도 다른 숫자가 발견된 경우
                        numarr[++board[i][j]]++;
                        numarr[++board[a][b]] += cnt;
                        checkPoint = true;
                    }
                    else cnt++; // 발견될 경우를 대비한 변수
                else numarr[++board[i][j]]++; // 한번이라도 다른 숫자가 발견된 이후부터는 바로 카운트 
            }
        }
        if(checkPoint == 0) numarr[++board[a][b]]++; // 다른 숫자가 발견되지 않은 경우
        return ;
    }
    // 재귀식
    for(int i=a; i < a+n; i++){
        for(int j=b; j < b+n; j++){
            if(board[a][b] != board[i][j]){ // 한번이라도 동일하지 않은 숫자가 있다면 종이 9 조각
                n = n/3;
                CutPaper(a, b, n); // 0 0 3
                CutPaper(a, b+n ,n); // 0 3 3
                CutPaper(a, b+n+n, n); // 0 6 3
                CutPaper(a+n, b, n); // 3 0 3
                CutPaper(a+n, b+n, n);
                CutPaper(a+n, b+n+n ,n);
                CutPaper(a+n+n, b, n);
                CutPaper(a+n+n, b+n, n);
                CutPaper(a+n+n, b+n+n, n);
                return;
            }
        }
    }
    numarr[++board[a][b]]++;
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cin >> board[i][j];  
        }
    }
    CutPaper(0,0,N);

    for(int i=0; i < 3; i++) cout << numarr[i] << "\n";
}

// 틀린 이유 : 메모리 초과 (int board[10000][10000] => int board[2500][2500] )
// 틀린 이유 : 재귀식 for 문 돌릴때 범위 설정 잘못함 (n -> a+n)


// 다른 방법 (base condition : n==1)
/*
//해당 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
bool check(int x, int y, int n) {
  for (int i = x; i < x + n; i++)
  for (int j = y; j < y + n; j++)
    if (paper[x][y] != paper[i][j])
    return false;
  return true;
}
void solve(int x, int y, int z)
{
  if (check(x, y, z)) {
    cnt[paper[x][y] + 1] += 1;
    return;
  }
  int n = z / 3;
  for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
    solve(x + i * n, y + j * n, n);
}
*/
