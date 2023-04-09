// https://www.acmicpc.net/problem/1629
// 1629��. ����

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


// Ʋ�� ���� : int ���
// Ʋ�� ���� : B �� 1�� ��� A % C �� ����ؾ� �ϴµ� A ��� (A�� B���� ���� �Ŷ� ������.)
// Ʋ�� ���� : 2k+1 �� ���(B % 2 == 1) A�� ���ϱ� ���� C�� ������ ���Ŀ� �� C�� ������� ��. (�й� ��Ģ�� �����ؼ� �����µ�, 21���� ���� ���ϴ� ���� ���� �����÷ο찡 �߻��� �� ����)

// ó�� �ڵ�
// int Calculate(int A, int B, int C)
// {
//     int remain;

//     if(B == 1) return A;
    
//     if(B % 2 == 1) return (Calculate(A, B/2, C) * Calculate(A, B/2, C) * A) % C;
//     else return (Calculate(A, B/2, C) * Calculate(A, B/2, C)) % C;
    
// }

// �ð� ���⵵ : O(logb)