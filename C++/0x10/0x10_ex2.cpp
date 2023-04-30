// https://www.acmicpc.net/problem/9095
// 9095번. 1,2,3 더하기

#include <bits/stdc++.h>

using namespace std;

int table[15]; // i 를 1,2,3의 합으로 나타내는 방법의 수
int num;

void InputUserData(){
        cin >> num;
}

void TableDataReset(){
    table[1] = 1;
    table[2] = 2; 
    table[3] = 4;
}

void CalTable(){
    for(int i = 4; i <= num ; i++){
        table[i] = table[i-1] + table[i-2] + table[i-3];
    }
}

void OutputResultData(){
    cout << table[num] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt; 
    while(cnt--){
        InputUserData();
        TableDataReset();
        CalTable();
        OutputResultData();
    }
}


// 백트래킹
// 10중 for문

/*
미리 다 구해놓기
#include <bits/stdc++.h>

using namespace std;

int table[15]; // i 를 1,2,3의 합으로 나타내는 방법의 수
int num;

void InputUserData(){
        cin >> num;
}

void TableDataReset(){
    table[1] = 1;
    table[2] = 2; 
    table[3] = 4;
}

void MakeTable(){
    TableDataReset();
    for(int i = 4; i <= 11 ; i++){
        table[i] = table[i-1] + table[i-2] + table[i-3];
    }
}

void OutputResultData(){
    cout << table[num] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    MakeTable();

    int cnt;
    cin >> cnt; 
    while(cnt--){
        InputUserData();
        OutputResultData();
    }
}
*/