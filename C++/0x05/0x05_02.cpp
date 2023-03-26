// https://www.acmicpc.net/problem/10773
// 10773¹ø. Á¦·Î

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int cnt, num, sum=0;
    cin >> cnt;

    while(cnt--)
    {
        cin >> num;
        if(num == 0) s.pop();
        else s.push(num);
    }

    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum << "\n";
}

