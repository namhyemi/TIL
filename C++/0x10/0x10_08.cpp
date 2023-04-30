// https://www.acmicpc.net/problem/9461
// 9461번. 파도반 수열

#include <bits/stdc++.h>

using namespace std;

long long P[105];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1; 
    P[4] = 2;
    P[5] = 2;

    for(int i=6; i<=100; i++){
        P[i] = P[i-5] + P[i-1];
    }

    int num;
    while(cnt--){
        cin >> num;
        cout << P[num] << "\n";
    }
}


// 틀린 이유 : 오버플로우(자료형 int -> long long)