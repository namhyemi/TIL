// https://www.acmicpc.net/problem/11726
// 11726��. 2xn Ÿ�ϸ�

#include <bits/stdc++.h>

using namespace std;

int tile[1000]; 
int N;

void InputUserData(){
    cin >> N;
}

void CalTile(){
    tile[1] = 1; 
    tile[2] = 2; 

    for(int i=3; i<=N; i++) { tile[i] = (tile[i-1] + tile[i-2]) % 10007; }
}

void OutputResultData(){
    cout << tile[N]  << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    CalTile();
    OutputResultData();
}

// Ʋ�� ���� : �����÷ο� (�������� ���������� ���϶�� ���� ���� ĳġ�ϱ�)

// �ٽ� : DP �������� ��ġä��