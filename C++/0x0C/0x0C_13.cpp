// https://www.acmicpc.net/problem/1759
// 1759번. 암호 만들기

#include<bits/stdc++.h>

using namespace std;

int N, M;
int alp_v=0, alp_c=0;
char user_arr[20];
int result_arr[20];
bool isused[20];

void func(int n){
    //  base condition (모음 최소 한개, 자음 최소 둘)
    if(n==M && alp_v > 0 && alp_c > 1){  
        for(int i=0; i<M; i++) cout << user_arr[result_arr[i]];
        cout << "\n";
        return ;
    }

    int st=0;
    if(n>0) st = result_arr[n-1]+1;
    for(int i=st; i<N; i++){
        if(user_arr[i] == 'a' || user_arr[i] == 'e' || user_arr[i] == 'i' || user_arr[i] == 'o' || user_arr[i] == 'u') alp_v++;
        else alp_c++;
        result_arr[n] = i;
        func(n+1);
        if(user_arr[i] == 'a' || user_arr[i] == 'e' || user_arr[i] == 'i' || user_arr[i] == 'o' || user_arr[i] == 'u') alp_v--;
        else alp_c--;        
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i=0; i<N; i++) cin >> user_arr[i];    
    sort(user_arr, user_arr+N);

    func(0);
}

// 틀린 이유 : 출력 형식 오류 (띄어쓰기함)

/*
// 다른 해답 : 출력할 때 모음과 자음 개수 확인
*/