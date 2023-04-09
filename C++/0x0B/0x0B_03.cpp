// https://www.acmicpc.net/problem/2630
// 2630��. ������ �����

#include<bits/stdc++.h>

using namespace std;

int board[200][200];
int numarr[2] = {0};

bool check(int a, int b, int n){
    for(int i = a; i < a+n; i++)
        for(int j = b; j < b+n; j++)
            if(board[a][b] != board[i][j])
                return false;
    return true;
}

void CutPaper(int a, int b, int n){
    // base conditoin : �� ���ڰ� ��� ���� ���(�ּ� �ڱ� �ڽŰ���)
    if(check(a, b, n)){
        numarr[board[a][b]]++;
        return;
    }

    //���
    n = n/2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            CutPaper(a+i*n, b+j*n ,n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> board[i][j];      
    
    CutPaper(0, 0, N);

    for(int i=0; i < 2; i++) cout << numarr[i] << "\n";
}
