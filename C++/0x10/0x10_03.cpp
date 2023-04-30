// https://www.acmicpc.net/problem/11727
// 11727��. 2��n Ÿ�ϸ� 2

#include <bits/stdc++.h>

using namespace std;

int n;
int tile[1005];

void InputUserData(){
    cin >> n;
}

void CheckTile(){
    tile[1] = 1;
    tile[2] = 3;

    for(int i=3; i<=n; i++){
        tile[i] = (tile[i-1] + tile[i-2] * 2) % 10007;
    }
}

void OutputResultData(){
    cout << tile[n] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    CheckTile();
    OutputResultData();
}


// Ʋ�� ���� : ��Ÿ�ӿ���(OutofBound) - �迭 ���� �Ű澲��