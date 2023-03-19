// 2441¹ø. º° Âï±â-4

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
        for(int j=0 ; j < i; j++) cout << ' ';
        for(int j=0 ; j < a-i ; j++) cout << '*';
        cout << "\n";
    }
}