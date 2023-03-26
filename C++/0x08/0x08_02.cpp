// https://www.acmicpc.net/problem/9012
// 9012¹ø. °ýÈ£

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    while(num--)
    {
        stack<char> s;
        string user_str;    
        cin >> user_str;

        for(auto str : user_str)
        {
            if(str == '(')
            {
                 s.push('(');
            }
            else if(str == ')') 
            {
                if(!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else s.push(')');
            }
            else ;
        }
        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}