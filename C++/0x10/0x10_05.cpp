// https://www.acmicpc.net/problem/1912
// 1912번. 연속합

#include <bits/stdc++.h>

using namespace std;

int cnt;
int min_minus = -1000;
int minus_cnt = 0;
int max_sum = 0;


void InputUserData(){
    cin >> cnt;
}

void Check(){
    int num;
    int sum = 0;

    for(int i=0; i<cnt; i++){
        cin >> num;

        if(num >= 0){
            if(sum < 0) sum = 0;
            sum += num;
        }
        else{
            minus_cnt++;

            if(max_sum < sum) max_sum = sum;
            sum += num;

            if(min_minus < num) min_minus = num;
        }

        if(i==cnt-1){ 
            max_sum = max(sum, max_sum);
        }
    }
}

void OutputResultData(){
    if(minus_cnt == cnt){
        cout << min_minus;
    }
    else{
        cout << max_sum << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    Check();
    OutputResultData();
}
