// https://www.acmicpc.net/problem/10799
// 10799번. 쇠막대기

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    int cnt=0, result=0;
    string user_str;

    cin >> user_str;

    for(auto C : user_str)
    {
        if(C == '(')
        {
            S.push('(');
            cnt++;
        }
        else if(C == ')')
        {
            if(S.top() == '(')
            {
                cnt--;
                result += cnt;
                S.push(')');
            }
            else if(S.top() == ')')
            {
                cnt--;
                result++;
                S.push(')');
            }
            else ;
        }
        else ;
    }
    cout << result << "\n";
}

// 틀린 이유 찾아야 함.


/*
// stack 안씀
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt=0, result=0;
    bool laser = false;
    string user_str;

    cin >> user_str;

    for(auto C : user_str)
    {
        if(C == '(')
        {
            cnt++;
            laser = false;
        }
        else if(C == ')')
        {
            if(laser == false)
            {
                laser = true;
                cnt--;
                result += cnt;
            }
            else if(laser == true)
            {
                cnt--;
                result++;
            }
            else ;
        }
        else ;
    }
    cout << result << "\n";
}
*/