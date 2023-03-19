// https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/0x03.md
// 10807번. 개수 세기


#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[201] = {};
    int num, a;

    cin >> num;
    for(int i=0; i < num ; i++)
    {
        cin >> a;
        arr[a+100]++;
    }
    cin >> a;
    
    cout << arr[a+100] << "\n";

}