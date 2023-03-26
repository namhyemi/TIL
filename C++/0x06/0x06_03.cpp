// https://www.acmicpc.net/problem/2164
// 2164번. 카드2

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int num;

    cin >> num;
    for(int i=1; i <= num; i++)
    {
        Q.push(i);
    }

    while(Q.size() > 1)
    {
        Q.pop();
        num = Q.front();
        Q.push(num);
        Q.pop();
    }
    cout << Q.front() << "\n";
}

// 실수 : for문 돌릴때 Q.push(i) 해야하는데 Q.push(num) 해서 헤맴