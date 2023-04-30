// https://www.acmicpc.net/problem/11727
// 11727번. 2×n 타일링 2

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


// 틀린 이유 : 런타임에러(OutofBound) - 배열 범위 신경쓰기