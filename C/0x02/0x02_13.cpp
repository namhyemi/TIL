// 10093��. ����

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long a,b,n,m;

    cin >> a >> b;

    m = max(a,b);
    n = min(a,b);

    if(m == n || m-n == 1) cout << 0;
    else 
        cout << m-n-1 << '\n';
        for(unsigned long i=n+1; i<m; i++)
        {
            cout << i << ' ';
        }
}

// Ʋ�� ���� : �ڷ��� ��Ȯ�� �ϱ� �ʿ�.
// Ʋ�� ���� : ����� �� ���� ����(�� ������ ���� ���)

// unsinged long : 4ms, long long : 16ms (? -> X)