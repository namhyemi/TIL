// https://www.acmicpc.net/problem/11047
// 11047번. 동전 0

#include <bits/stdc++.h>

using namespace std;

int wallet[15];
int wallet_cnt, money;
int cnt;

void InputUserData(){
    cin >> wallet_cnt >> money;
    for(int i=1; i <= wallet_cnt; i++){ cin >> wallet[i];}
}

void Calculator(){
    int start;
    for(int i=wallet_cnt; i > 0; i--){ 
        if(wallet[i] <= money){
            start = i;
            break;
        }
    }

    for(int i=start; i > 0; i--){
        while(1){
            if(money < wallet[i]) break;
            money -= wallet[i];
            cnt++;
        }
    }
}

void OutputResultData(){
    cout << cnt << "\n";
} 

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    Calculator();
    OutputResultData();
}

// 틀린 이유 : 부등호 사용시 등호 유념하기 

/*
더 간단한 코드
int n,k;
int a[15];
int ans=0;

cin >> n >> k;
for(int i=0; i<n; i++) cin >> a[i];
for(int i=n-1; i>=0; i--){
    ans += k/a[i];
    k %= a[i];
}
cout << ans;
*/

/*
문제+ : 위와 같은 방식 가능했던건 동전 간의 배수 관계가 성립했기 때문임.
        배수 관계 아닌경우의 반례(동전 1, 9, 10 돈 18 => 위 코드는 10 1개 1 8개로 9개가 나오지만 실제로는 9 2개로 가능하다)
        
조건이 약간만 달라져도 풀이가 달라질 수 있기 때문에 비슷한 문제를 풀어봤다고 풀이 방향 정하는 실수 하지 않기
*/
