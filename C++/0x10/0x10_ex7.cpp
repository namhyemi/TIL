// https://www.acmicpc.net/problem/12852
// 12852번. 1로 만들기2

#include <bits/stdc++.h>

using namespace std;

int table[1000005];
int route[1000005];
int num;

void InputUserData(){
    cin >> num;
}

void Caltable(){
    table[1] = 0; route[1] = 0;

    for(int i=2; i <= num; i++){
        table[i] = table[i-1] + 1; route[i] = i-1;
        if(i % 2 == 0 && table[i] > table[i/2] + 1){ table[i] = table[i/2] + 1; route[i] = i/2; }
        if(i % 3 == 0 && table[i] > table[i/3] + 1){ table[i] = table[i/3] + 1; route[i] = i/3; }
    }
}

void OutputResultData(){
    cout << table[num] << "\n";
    while(1){
        cout << num << " ";
        if(num == 1) break;
        num = route[num];
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    Caltable();
    OutputResultData();
}

// BFS 도 경로 복원 가능