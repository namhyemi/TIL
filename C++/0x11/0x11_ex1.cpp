// https://www.acmicpc.net/problem/11047
// 11047��. ���� 0

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

// Ʋ�� ���� : �ε�ȣ ���� ��ȣ �����ϱ� 

/*
�� ������ �ڵ�
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
����+ : ���� ���� ��� �����ߴ��� ���� ���� ��� ���谡 �����߱� ������.
        ��� ���� �ƴѰ���� �ݷ�(���� 1, 9, 10 �� 18 => �� �ڵ�� 10 1�� 1 8���� 9���� �������� �����δ� 9 2���� �����ϴ�)
        
������ �ణ�� �޶����� Ǯ�̰� �޶��� �� �ֱ� ������ ����� ������ Ǯ��ôٰ� Ǯ�� ���� ���ϴ� �Ǽ� ���� �ʱ�
*/
