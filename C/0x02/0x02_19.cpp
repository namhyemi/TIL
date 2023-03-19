// 2440¹ø. º° Âï±â-3

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;

    cin >> a;

    for(int i=0; i < a; i++)
    {
        for(int j=a-i; j > 0; j--)
        {
            cout << '*';
        }
        cout << '\n';
    }
}