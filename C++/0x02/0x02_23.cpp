// 2444¹ø. º° Âï±â-7

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;

    cin >> a;

    for(int i=0 ; i < a ;i++)
    {
        for(int j=0; j < a-i-1; j++) cout << " ";
        for(int j=0; j < 2*i+1; j++) cout << "*";
        cout << '\n';
    }
    for(int i=0; i < a-1 ; i++)
    {
        for(int j=0; j < i+1 ; j++) cout << " ";
        for(int j=2*(a-i-1)-1; j > 0 ; j--) cout << "*";
        cout << '\n';
    }

}