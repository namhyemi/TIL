// https://www.acmicpc.net/problem/2164
// 2164��. ī��2

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

// �Ǽ� : for�� ������ Q.push(i) �ؾ��ϴµ� Q.push(num) �ؼ� ���