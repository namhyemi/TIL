// https://www.acmicpc.net/problem/11501
// 11501번. 주식

#include <bits/stdc++.h>

using namespace std;

int money[1000005];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt;
    while(cnt--){
        int n;
        cin >> n;
        fill(money, money+n, 0);
        for(int i=1; i <= n; i++) cin >> money[i];

        long long sum_money = 0;
        int max_num = 0;
        for(int i=n; i > 0; i--){
            if(max_num < money[i]) max_num = money[i];
            else sum_money += max_num - money[i];

        }
        cout << sum_money << "\n";
    }
}

// 틀린 이유 : 자료형 (int -> long long)