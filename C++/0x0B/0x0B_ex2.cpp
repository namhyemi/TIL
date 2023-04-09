// https://www.acmicpc.net/problem/11729
// 11729��. �ϳ��� ž �̵� ����

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

// �Ǽ� : �Լ� ���ϰ��� void �� ��쿡�� ������ �Ұ��� �ϴ�.     hanoi(a, 6-a-b, n-1) + hanoi(a, b, 1) + hanoi(6-a-b, b, n-1);

// Ʋ�� ���� : pow(2,20) �� �Ǹ� 1.04858e+006 �� ��µȴ�. (pow �� �⺻������ �Լ� ���ڰ��� ���� ���� double ��)
// (�ٸ� pow(2,3)�� ��� ���ϰ��� ������ ����Ǵ� �� C++���� �⺻������ �Ҽ����� 0�̸� ������� �ʱ� ����)

// 2�� �ŵ� ������ ��Ʈ ������(shift)�� ����� �� �ִ�. �ӵ��鿡�� ��Ʈ ������ �� ����ϴ�. pow(2,n) == (1<<n) 
