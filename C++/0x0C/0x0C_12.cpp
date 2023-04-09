// https://www.acmicpc.net/problem/6603
// 6603번. 로또

#include<bits/stdc++.h>

using namespace std;

int N;
int user_arr[15];
int result_arr[15];
bool isused[15];

void func(int n){
    if(n==6){
        for(int i=0; i<6; i++) cout << user_arr[result_arr[i]] << " ";
        cout << "\n";
        return;
    }

    int st = 0;
    if(n > 0) st = result_arr[n-1]+1;
    for(int i=st; i<N; i++){
        if(!isused[i]){
            isused[i] = true;
            result_arr[n] = i;
            func(n+1);
            isused[i] = false;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N != 0){
        for(int i=0; i<N; i++){
            cin >> user_arr[i];
        }

        func(0);

        cout << "\n";
        cin >> N;
    }
}

// 틀린 이유 : 출력 형식이 잘못되었습니다. (줄 띄우기)