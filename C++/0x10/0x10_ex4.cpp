// https://www.acmicpc.net/problem/1149
// 1149¹ø. RGB°Å¸®

#include <bits/stdc++.h>

using namespace std;

int house[1005][3]; 
int cnt;

void CalTable(int i, int R, int G, int B){
    house[i][0] = min(house[i-1][1], house[i-1][2]) + R;
    house[i][1] = min(house[i-1][0], house[i-1][2]) + G;
    house[i][2] = min(house[i-1][0], house[i-1][1]) + B;
}

void InputUserData(int i){
    int R, G, B;
    cin >> R >> G >> B;

    if(i==1) { house[1][0] = R; house[1][1] = G; house[1][2] = B; }
    else CalTable(i, R, G, B);
}

void InputCnt(){
    cin >> cnt;
    for(int i=1; i<=cnt ;i++) { InputUserData(i); }
}

void OutputResultData(){
    cout << min(house[cnt][0], min(house[cnt][1], house[cnt][2])) << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputCnt();
    OutputResultData();
}

