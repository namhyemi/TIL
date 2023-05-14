// https://www.acmicpc.net/problem/9613
// 9613. GCD ��

#include<bits/stdc++.h>

using namespace std;

int arr[105];

int GCD(int a, int b){
    if(a == 0) return b;
    return GCD(b%a, a);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    int cnt;
    while(num--){
        cin >> cnt;

        fill(arr, arr+cnt, 0);
        for(int i=0; i < cnt; i++){
            cin >> arr[i];
        }

        long long sum = 0;
        for(int i=0; i < cnt-1; i++){
            for(int j=i+1; j < cnt; j++){
                if(arr[i] < arr[j])
                    sum += GCD(arr[i], arr[j]);
                else 
                    sum += GCD(arr[j], arr[i]);
            }
        }

        cout << sum << "\n";
    }
}

// Ʋ�� ���� : ��� - GCD ��� (������, ū��)
// Ʋ�� ���� : �ڷ���(int -> long long)

// �ٸ� �ڵ� : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/9613.cpp