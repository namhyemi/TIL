// https://www.acmicpc.net/problem/10989
// 10989번. 수 정렬하기3

#include<bits/stdc++.h>

using namespace std;

int number[10000];

void InputUserDate(){
    int cnt, num;
    cin >> cnt;
    while(cnt--){
        cin >> num;
        number[num-1]++;
    }
}

void OutputData(){
    for(int i=0; i < 10000; i++){
        while(number[i]--){
            cout << i+1 << "\n";
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    OutputData();
}

// 틀린 이유 : 메모리 초과 => int형 천만개면 약 40MB 메모리 사용(https://www.acmicpc.net/board/view/26132)
// 틀린 이유 : 시간 초과 => ios::sync_with_stdio(0);, cin.tie(0); (https://www.acmicpc.net/problem/15552)
// 틀린 이유 : 범위 실수 => 10000 포함