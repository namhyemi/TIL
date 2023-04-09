// https://www.acmicpc.net/problem/15652
// 15652¹ø. N °ú M (4)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[10];
void func(int n){
    if(n==M){
        for(int i=0; i<M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }

    int st = 1;
    if(n>0) st = arr[n-1];
    for(int i=st; i<=N; i++){
        arr[n] = i;
        func(n+1);
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0);
}