// https://www.acmicpc.net/problem/1463
// 1463번. 1로 만들기

#include <bits/stdc++.h>

using namespace std;

int table[1000005];
int num;

void InputUserData(){
    cin >> num;
}

void CheckTable(){
    table[1] = 0;

    for(int i=2; i <= num; i++){
        table[i] = table[i-1] + 1;
        if(i%2 == 0) table[i] = min(table[i], table[i/2]+1);
        if(i%3 == 0) table[i] = min(table[i], table[i/3]+1);
    }
}

void OutputResultData(){
    cout << table[num] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    CheckTable();
    OutputResultData();
}

// BFS