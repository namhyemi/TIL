// https://www.acmicpc.net/problem/15654
// 15654��. N �� M (5)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int user_arr[10];
int arr[10];
bool isused[10005];

void func(int n){
    if(n==M){
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout <<"\n";
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!isused[user_arr[i]]){
            isused[user_arr[i]] = true;
            arr[n] = user_arr[i];
            func(n+1);
            isused[user_arr[i]] = false;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> user_arr[i];
    sort(user_arr, user_arr+N);

    func(0);
}

// Ʋ������ : �湮 ���� �迭 ũ��(10 --> 10005)