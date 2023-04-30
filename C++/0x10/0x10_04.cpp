// https://www.acmicpc.net/problem/2193
// 2193번. 이친수

#include <bits/stdc++.h>

using namespace std;

int n;
long long binary[100][2]; // [문자열 길이][현재 값이 0인지 1인지]

void InputUserData(){
    cin >> n;
}

void Check(){
    binary[1][0] = 0; binary[1][1] = 1;
    
    for(int i=2; i<=n; i++){
        binary[i][0] = binary[i-1][0] + binary[i-1][1];
        binary[i][1] = binary[i-1][0];
    }
}

void OutputResultData(){
    cout << binary[n][0] + binary[n][1] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    Check();
    OutputResultData();
}

// 틀린 이유 : int형 -> long long 형