// https://www.acmicpc.net/problem/1026
// 1026번. 보물

#include <bits/stdc++.h>

using namespace std;

int cnt;
int A[50];
int B[50];
int result = 0;

void InputUserData(){
    cin >> cnt;
    for(int i=0; i<cnt; i++){ cin >> A[i]; }
    for(int i=0; i<cnt; i++){ cin >> B[i]; }
}

void SortArr(){
    sort(A, A+cnt);
    sort(B, B+cnt);
}

void Calculator(){
    for(int i = 0; i < cnt; i++){
        result += A[i] * B[cnt-1-i];
    }
}

void OutputResultData(){
    cout << result << "\n";
} 

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    SortArr();
    Calculator();
    OutputResultData();
}

// 재배열 부등식 (큰원소x큰원소 = 최대, 큰원소x작은원소 = 최소)
