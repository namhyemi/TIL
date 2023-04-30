// https://www.acmicpc.net/problem/1003
// 1003번. 피보나치 함수

#include <bits/stdc++.h>

using namespace std;

int fibo[45][2];

int InputUserData(){
    int num;
    cin >> num;

    return num;
}

void OutputResultData(int n){
    cout << fibo[n][0] << " " << fibo[n][1] << "\n";
}

int InputCount(){
    int cnt;
    cin >> cnt;
    while(cnt--){
        OutputResultData(InputUserData());
    }
}

void Fibonacci(){
    fibo[0][0] = 1; fibo[0][1] = 0;
    fibo[1][0] = 0; fibo[1][1] = 1;

    for(int i=2; i <= 40; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    Fibonacci();
    InputCount();
}


// 틀린 이유 : 출력 초과
// (https://www.acmicpc.net/board/view/23037)

// 참고(원인X)
// 정답은 출력이 바로바로 되고, 위 코드는 결과를 모았다가 한번에 출력 => "\n" 대신 endl
// (https://www.acmicpc.net/board/view/25213)

