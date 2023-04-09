// https://www.acmicpc.net/problem/11729
// 11729번. 하노이 탑 이동 순서

#include<bits/stdc++.h>

using namespace std;

void hanoi(int a, int b, int n){
    
    if(n == 1){
        cout << a << " " << b << "\n";
        return ;
    }

    hanoi(a, 6-a-b, n-1);
    hanoi(a, b, 1);
    hanoi(6-a-b, b, n-1);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    hanoi(1,3,n);
}

// 실수 : 함수 리턴값이 void 인 경우에는 연산이 불가능 하다.     hanoi(a, 6-a-b, n-1) + hanoi(a, b, 1) + hanoi(6-a-b, b, n-1);

// 틀린 이유 : pow(2,20) 이 되면 1.04858e+006 로 출력된다. (pow 는 기본적으로 함수 인자값과 리턴 값이 double 형)
// (다만 pow(2,3)의 경우 리턴값이 정수로 출려되는 건 C++에서 기본적으로 소수점이 0이면 출력하지 않기 때문)

// 2의 거듭 제곱은 비트 연산자(shift)로 계산할 수 있다. 속도면에서 비트 연산이 더 우월하다. pow(2,n) == (1<<n) 
