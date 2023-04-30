// https://www.acmicpc.net/problem/2193
// 2193��. ��ģ��

#include <bits/stdc++.h>

using namespace std;

int n;
long long binary[100][2]; // [���ڿ� ����][���� ���� 0���� 1����]

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

// Ʋ�� ���� : int�� -> long long ��