// https://www.acmicpc.net/problem/1026
// 1026��. ����

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

// ��迭 �ε�� (ū����xū���� = �ִ�, ū����x�������� = �ּ�)
