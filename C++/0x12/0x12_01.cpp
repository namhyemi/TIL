// https://www.acmicpc.net/problem/15894
// 15894. 수학은 체육과목입니다

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long num;
    cin >> num;

    cout << (3 * num) + num << "\n";
}

// 틀린 이유 : 자료형(int -> long long) - 코드 제출 전 최대 큰 입력값 출력해보기
// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/15894.cpp