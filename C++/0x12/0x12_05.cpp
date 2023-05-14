// https://www.acmicpc.net/problem/4948
// 4948. 베르트랑 공준

#include<bits/stdc++.h>

using namespace std;

#define MAX 123456*2

vector<bool> v(MAX+1, true);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    v[1] = false;
    for(int i=2; i*i <= MAX; i++){
        if(!v[i]) continue;
        for(int j=i*i; j <= MAX; j+=i){
            v[j] = false; 
        }
    }

    int num, cnt;
    while(1){
        cin >> num;
        if(num == 0) break;

        cnt = 0;
        for(int i=num+1; i<=num*2; i++){
            if(v[i]) cnt++;
        }
        cout << cnt << "\n";
    }
}

// 실수 : 이중for문 시 변수 주의 
// 시간 초과 걱정

// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/4948.cpp