// https://www.acmicpc.net/problem/1929
// 1929. 소수 구하기

#include<bits/stdc++.h>

using namespace std;

vector<bool> v(1000005, true);

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int start, end;
    cin >> start >> end;

    v[1] = false;
    for(int i=2; i*i <= end; i++){
        if(!v[i]) continue;
        for(int j=i*i; j <= end; j+=i){
            v[j] = false;
        }
    }

    for(int i=start ; i<=end; i++){
        if(v[i]) cout << i << "\n";
    }
}


// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/1929.cpp