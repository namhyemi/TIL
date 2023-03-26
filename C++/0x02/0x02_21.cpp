// 2442¹ø. º° Âï±â-5

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
        for(int j=0; j < a-i-1; j++) cout << ' ';
        for(int j=0; j < 2*i+1; j++) cout << "*";
        cout << "\n";
    }

}