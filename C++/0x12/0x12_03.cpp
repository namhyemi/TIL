// https://www.acmicpc.net/problem/2960
// 2960. 에라토스테네스의 체 

#include<bits/stdc++.h>

using namespace std;

bool arr[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int N, K;
    cin >> N >> K;

    for(int i=2; i <= N; i++){
        if(arr[i]) continue;
        else{
            arr[i] = true;
            cnt++;
            if(cnt==K){
                cout << i << "\n";
                break;
            }
        }
        for(int j=i*i; j <= N; j+=i){
            if(arr[j]) continue;
            arr[j] = true;
            cnt++;
            if(cnt==K){
                cout << j << "\n";
                break;
            }
        }
    }
}

// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/2960.cpp