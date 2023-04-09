// https://www.acmicpc.net/problem/1629
// 1629번. 곱셈

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll Calculate(ll A, ll B, ll C)
{
    if(B == 1) return A % C;

    if(B % 2 == 1) return (Calculate(A, B/2, C) * Calculate(A, B/2, C) % C) * A % C;
    else return (Calculate(A, B/2, C) * Calculate(A, B/2, C)) % C;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll InputDataA, InputDataB, InputDataC;
    cin >> InputDataA >> InputDataB >> InputDataC;

    cout << Calculate(InputDataA, InputDataB, InputDataC) << "\n";
}


// 틀린 이유 : int 사용
// 틀린 이유 : B 가 1인 경우 A % C 를 사용해야 하는데 A 사용 (A가 B보다 작을 거라 생각함.)
// 틀린 이유 : 2k+1 인 경우(B % 2 == 1) A를 곱하기 전에 C를 나누고 이후에 또 C를 나눠줘야 함. (분배 법칙을 생각해서 적었는데, 21억을 세번 곱하는 경우로 인해 오버플로우가 발생할 수 있음)

// 처음 코드
// int Calculate(int A, int B, int C)
// {
//     int remain;

//     if(B == 1) return A;
    
//     if(B % 2 == 1) return (Calculate(A, B/2, C) * Calculate(A, B/2, C) * A) % C;
//     else return (Calculate(A, B/2, C) * Calculate(A, B/2, C)) % C;
    
// }

// 시간 복잡도 : O(logb)