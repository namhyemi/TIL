// https://www.acmicpc.net/problem/11726
// 11726번. 2xn 타일링

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

// 틀린 이유 : 오버플로우 (문제에서 나머지값을 구하라는 것을 통해 캐치하기)

// 핵심 : DP 문제인지 눈치채기