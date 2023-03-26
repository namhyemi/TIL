// https://www.acmicpc.net/problem/4949
// 4949��.�������� ����

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

// �Ǽ� : stack �� �ݺ��� �ۿ��� �����ߴٸ� Ŭ���� ������ �ʿ�������  while( !s.empty() ) s.pop(); >> �׳� �ݺ��� �ȿ� ������.

// Ʋ�� ���� : ��ȣ�� �����⸸ �ϰ� ������ ���� ��� ó�� ���� if(!s.empty()) result = 0;