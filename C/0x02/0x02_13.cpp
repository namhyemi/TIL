// 10093번. 숫자

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

// 틀린 이유 : 자료형 정확한 암기 필요.
// 틀린 이유 : 경우의 수 생각 부족(두 정수가 같은 경우)

// unsinged long : 4ms, long long : 16ms (? -> X)