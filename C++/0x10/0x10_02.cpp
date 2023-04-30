// https://www.acmicpc.net/problem/1932
// 1932번. 정수 삼각형

#include <bits/stdc++.h>

using namespace std;

int cnt;
int odd_result[500];
int even_result[500];

void InputUserData(){
    cin >> cnt;

    int tmp;
    for(int i=1; i<=cnt; i++){
        for(int j=0; j < i; j++){
            cin >> tmp; 
            if(i%2!=0){ 
                if(j==0) odd_result[j] = even_result[j] + tmp;
                else if(j==i-1) odd_result[j] = even_result[j-1] + tmp; 
                else odd_result[j] = max(even_result[j-1], even_result[j]) + tmp;
            }
            else{
                if(j==0) even_result[j] = odd_result[j] + tmp;
                else if(j==i-1) even_result[j] = odd_result[j-1] + tmp;
                else even_result[j] = max(odd_result[j-1], odd_result[j]) + tmp;
            }
        }
    }
}

void OutputResultData(){
    if(cnt % 2 != 0){    
        sort(odd_result, odd_result+cnt);
        cout << odd_result[cnt-1] << "\n";
    }
    else{
        sort(even_result, even_result+cnt);
        cout << even_result[cnt-1] << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    OutputResultData();
}
