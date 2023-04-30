// https://www.acmicpc.net/problem/2579
// 2579번. 계단 오르기

#include <bits/stdc++.h>

using namespace std;

int stair[305];
int step[305][2]; 
int num;

void InputUserData(){
    cin >> num;
    for(int i=1; i <= num; i++) { cin >> stair[i]; }
}

void CalTable(){
    step[0][1] = step[0][2] = 0;
    step[1][1] = stair[1], step[1][2] = 0;

    for(int i=2; i <= num; i++){
        step[i][1] = max(step[i-2][1], step[i-2][2]) + stair[i];
        step[i][2] = step[i-1][1] + stair[i];
    }
}

void OutputResultData(){
    cout << max(step[num][1], step[num][2]) << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    CalTable();
    OutputResultData();
}

// 백트래킹 (N이20이하인 경우 가능)


// DP
// D[i][j] : 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값 (i번째 계단 필수)
// D[k][1] = k-1 번째 계단을 밟지 않고 k-2 번째 계단을 밟았다는 의미

/*
// D[i] = i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최소값, 단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함.


for(int i=1; i <= n; i++){
    cin >> s[i];
    sum += s[i];
}

if(n <= 2){
    cout << sum;
    return 0; 
}

D[1] = S[1];
D[2] = S[2];
D[3] = S[3];

for(int i=3; i< num; i++) { D[i] = min(D[i-2], D[i-3]) + S[i]; }

cout << tot - min(D[i-1], D[i-2]);

*/