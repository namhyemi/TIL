// https://www.acmicpc.net/problem/2217
// 2217번. 로프

// 문제 이해

#include <bits/stdc++.h>

using namespace std;

int cnt;
int max_weight=0;
int rope[100005];

void InputUserData(){
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        cin >> rope[i];
    }
}

void SortRope(){
    sort(rope, rope+cnt);
}

void Calculator(){
    SortRope();
    for(int i=1; i<=cnt; i++){ // 로프 i개 선택
        max_weight = max(rope[cnt-i] * i, max_weight);
    }
}

void OutputResultData(){
    cout << max_weight << "\n";
} 

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    Calculator();
    OutputResultData();
}