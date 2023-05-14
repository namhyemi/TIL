// https://www.acmicpc.net/problem/4796
// 4796. 캠핑

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, L, V;
    int i=1;
    while(1){
        cin >> P >> L >> V;
        if(P == 0 && L == 0 && V == 0) break;

        int result = (V % L > P) ? P : V % L; 
        result += (V / L) * P;

        cout << "Case " << i++ << ": " << result << "\n";
    }
}

// 틀린 이유 : 계산
// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/4796.cpp