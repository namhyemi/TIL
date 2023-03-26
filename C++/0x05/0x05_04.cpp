// https://www.acmicpc.net/problem/2493
// 2493번. 탑

// 다시 풀어보기

#define X first
#define Y second

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> s;
    int cnt, num;

    cin >> cnt;
    for(int i=1; i <= cnt; i++)
    {
        cin >> num;
        while(!s.empty() && s.top().X <= num) s.pop();

        if(s.empty()) cout << 0 << " ";
        else cout << s.top().Y << " ";

        s.push({num, i});
    }
    cout << "\n";
}