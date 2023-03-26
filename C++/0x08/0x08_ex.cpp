// https://www.acmicpc.net/problem/4949
// 4949번.균형잡힌 세상

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string user_str;
    getline(cin, user_str);

    while(user_str != ".")
    {
        stack<int> s;
        int result = 1; // bool isVaild = true;

        for(int i=0; i < user_str.length(); i++)
        {
            if(user_str[i] == '[')
            {
                s.push(1);
            }
            else if(user_str[i] == ']')
            {
                if(!s.empty() && s.top() == 1)
                {
                    s.pop();
                }
                else 
                {   
                    result = 0;
                    break;
                }
            }
            else if(user_str[i] == '(')
            {
                s.push(2);
            }
            else if(user_str[i] == ')')
            {
                if(!s.empty() && s.top() == 2)
                {
                    s.pop();
                }
                else
                {   
                    result = 0;
                    break;
                }
            }
            else;
        }
        if(!s.empty()) result = 0;

        if(result == 1) cout << "yes\n";
        else cout << "no\n";

        getline(cin, user_str);
    }
}

// 실수 : stack 을 반복문 밖에서 선언했다면 클리어 과정이 필요했을듯  while( !s.empty() ) s.pop(); >> 그냥 반복문 안에 선언함.

// 틀린 이유 : 괄호가 열리기만 하고 닫히지 않은 경우 처리 안함 if(!s.empty()) result = 0;