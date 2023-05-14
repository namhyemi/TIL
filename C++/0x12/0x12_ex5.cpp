// https://www.acmicpc.net/problem/11050
// 11050. 이항 계수 1

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int sum = 1;
    for(int i=N-K+1; i <= N; i++){
        sum *= i;
    }
    for(int i=K; i>1; i--){
        sum /= i;
    }

    cout << sum << "\n";
}


// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/11050.cpp