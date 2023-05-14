// https://www.acmicpc.net/problem/11051
// 11051. ���� ��� 2

#include<bits/stdc++.h>

using namespace std;

int comb[1002][1002];
int mod = 10007;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1; i<= 1000; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
    }

    int N, K;
    cin >> N >> K;
    cout << comb[N][K] << "\n";
}


// �ٸ� �ڵ� : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/11051.cpp

// ���� ����