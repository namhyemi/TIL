// https://www.acmicpc.net/problem/11055
// 11055번. 가장 큰 증가하는 부분 수열

#include <bits/stdc++.h>

using namespace std;

int D[1005][2]; // [i][1] = 부분 수열 합 중 가장 큰 수 [i][0] = 현재 더한 수

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int max_num = 0;
    for(int cur=1; cur<=n; cur++){ 
        cin >> D[cur][0];
        D[cur][1] = D[cur][0];
        for(int b=1; b < cur; b++){ 
            if(D[b][0] < D[cur][0]){ // if.증가하는 수
                if(D[cur][1] < D[b][1] + D[cur][0]){ // if. 증가하는 부분 수열 중 합이 제일 큰 수 저장 
                    D[cur][1] = D[b][1] + D[cur][0];
                }
            }
        }
        if(D[cur][1] > max_num) max_num = D[cur][1]; // 가장 큰 값
    }
    cout << max_num << "\n";
}

// 틀린 이유 : 계산 (같이 동일한 경우도 포함)