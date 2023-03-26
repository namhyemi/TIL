// 2438¹ø. º° Âï±â-1

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
        for(int j=0; j < i+1; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}
