// https://www.acmicpc.net/problem/2579
// 2579��. ��� ������

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

// ��Ʈ��ŷ (N��20������ ��� ����)


// DP
// D[i][j] : ������� j���� ����� �����ؼ� ��� i��° ��ܱ��� �ö��� �� ���� ���� �ִ� (i��° ��� �ʼ�)
// D[k][1] = k-1 ��° ����� ���� �ʰ� k-2 ��° ����� ��Ҵٴ� �ǹ�

/*
// D[i] = i��° ��ܱ��� �ö��� �� ���� ���� ����� ���� �ּҰ�, �� i��° ����� �ݵ�� ���� ���� ������� �����ؾ� ��.


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