// 2480��. �ֻ��� ����

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[4];

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);

    if(a[0] == a[1])
        if(a[1] == a[2]) cout << 10000 + a[0] * 1000;
        else cout << 1000 + a[1] * 100;
    else 
        if(a[1] == a[2]) cout << 1000 + a[1] * 100;
        else cout << a[2] * 100;
        
    cout << '\n';
}

// if(a[0]==a[2]) cout << 10000 + a[0] * 1000;
// else if(a[0]==a[1] || a[1]==a[2]) cout << 1000 + a[1] * 100;
// else cout << a[2] * 100;