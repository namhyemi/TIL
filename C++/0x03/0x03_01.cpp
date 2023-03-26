// https://www.acmicpc.net/problem/2577
// 2577번. 숫자의 개수

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, x;
    int arr[10] = {};

    cin >> A >> B >> C;

    x = A * B * C;

    while(x>0)
    {
        arr[x%10]++;
        x = x/10;
    }
    for(int i=0; i < 10; i++) cout << arr[i] << "\n";
}