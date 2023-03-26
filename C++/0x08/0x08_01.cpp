// https://www.acmicpc.net/problem/3986
// 3986번. 좋은 단어

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    
    int num, cnt = 0;

    cin >> num;
    while(num--)
    {
        stack<char> s;
        string user_str;    
        cin >> user_str;

        for(auto a : user_str)
        {
            if(a == 'A')
            {
                if(!s.empty() && s.top() == 'A')
                {
                    s.pop();
                }
                else s.push('A');
            }
            else if(a == 'B') 
            {
                if(!s.empty() && s.top() == 'B')
                {
                    s.pop();
                }
                else s.push('B');
            }
            else ;
        }
        if(s.empty()) cnt++;
    }
    cout << cnt << "\n";
}