// https://www.acmicpc.net/problem/15655
// 15655¹ø. N °ú M (6)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int user_arr[10];
int arr[10];
int isused[10005];

void func(int n){
    if(n==M){
        for(int i=0; i<M ;i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(n > 0 && user_arr[i] <= arr[n-1]) continue;
        arr[n] = user_arr[i];
        func(n+1);
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