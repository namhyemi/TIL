// https://www.acmicpc.net/problem/11053
// 11053번. 가장 긴 증가하는 부분 수열

#include <bits/stdc++.h>

using namespace std;

int D[1005][2];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int max_len = 0;
    for(int cur = 1; cur <= n; cur++){
        cin >> D[cur][0];
        D[cur][1] = 1;

        for(int b = 1; b < cur; b++){
            if(D[b][0] < D[cur][0]){ // 값이 증가하는 경우 중
                if(D[cur][1] < D[b][1] + 1){  // 길이가 가장 긴 경우 저장
                    D[cur][1] = D[b][1] + 1;
                }
            }
        }
        max_len = max(max_len, D[cur][1]);
    }
    cout << max_len << "\n";
}

// 틀린 이유 : 런타임 에러(OufOfBounds) - 배열 선언 100 -> 1005 (실수)

// N = 1000 이기 때문에 O(N^2) 가능