// https://www.acmicpc.net/problem/1992
// 1992��. ����Ʈ��

#include<bits/stdc++.h>

using namespace std;

int board[65][65];

bool CheckArea(int a, int b, int n){
    for(int i=a; i<a+n; i++)
        for(int j=b; j<b+n; j++)
            if(board[a][b] != board[i][j])
                return false;
    return true;
}

void DivideArea(int a, int b, int n){
    // base condition (�ڱ� �ڽ�)
    if(CheckArea(a, b, n)){
        cout << board[a][b];
        return;
    }

    // ���
    n = n/2;
    cout << "(";
    for(int i=0; i < 2; i++){
        for(int j=0; j < 2; j++){
            DivideArea(a+i*n, b+j*n, n);
        }    
    }
    cout << ")";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int N;
    cin >> N;
    for(int i=0; i < N; i++){
        cin >> s;
        for(int j=0; j < N; j++)
            board[i][j] = s[j]-'0';
    }

    DivideArea(0,0,N);
}
