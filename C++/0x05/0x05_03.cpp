// https://www.acmicpc.net/problem/1874
// 1874번. 스택 수열

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int cnt, data=1;
    string str;

    cin >> cnt;
    
    for(int i=1 ; i <= cnt ; i++)
    {
        int num;
        cin >> num;
        while(data <= num)
        {
            s.push(data++);
            str += "+\n";
        }

        if(s.top() != num)
        {
            cout << "NO\n";
            return 0;
        }
        s.pop();
        str += "-\n";
    }
    cout << str;
}


// 종료 코드: 3221225477 (액세스 접근 문제) => 스택이 비었을때 s.top() 

// 다시 풀어보기