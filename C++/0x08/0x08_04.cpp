// https://www.acmicpc.net/problem/2504
// 2504��. ��ȣ�� ��

// �ٽ� Ǯ���

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string user_str;
    int num = 1, sum = 0;

    cin >> user_str;
    
    for(int i=0; i < user_str.length() ; i++)
    {
        if(user_str[i] == '(')
        {
            s.push('(');
            num *= 2;
        }
        else if(user_str[i] == ')')
        {
            if(s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if(user_str[i-1] == '(') sum += num;
            s.pop();
            num /= 2;
        }
        else if(user_str[i] == '[')
        {
            s.push('[');
            num *= 3;
        }
        else if(user_str[i] == ']')
        {
            if(s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if(user_str[i-1] == '[') sum += num;
            s.pop();
            num /= 3;
        }
    }
    if(s.empty()) cout << sum;
    else cout << 0;
}

// Ʋ�� ���� : ���°�ȣ�� �ִ� ��� ���� ����.




// pop() �Ҷ� ����ϴ� ��� (����� �۵� �ȵ�) -> Ʋ�� ���� : ����, ���� ���� ����(?)

// int main() 
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     stack<char> S;
//     string user_str;
//     bool isValue = true;
//     int sum = 0, result = 0, tmp = 0;

//     cin >> user_str;


    // for(int i=0; i < user_str.length() ; i++)
    // {
    //     if(user_str[i] == '(') S.push('(');
    //     else if(user_str[i] == ')')
    //     {
    //         if(!S.empty() && S.top() == '(')
    //         {
    //             S.pop();
    //             if(user_str[i-1] != '(') sum *=2;    
    //             else if(user_str[i-1] == '(') sum += 2;
    //             else ;
    //         }
    //         else
    //         {
    //             isValue = false;
    //             break;
    //         }
    //     }
    //     else if(user_str[i] == '[') S.push('[');
    //     else if(user_str[i] == ']')
    //     {
    //         if(!S.empty() && S.top() == '[')
    //         {
    //             S.pop();
    //             if(user_str[i-1] != '[') sum *= 3;
    //             else if(user_str[i-1] == '[') sum += 3;
    //             else ;
    //         }
    //         else
    //         {
    //             isValue = false;
    //             break;
    //         }
    //     }
    //     else ;

    //     if(S.empty())
    //     {
    //         result += sum;
    //         sum = 0;
    //     }
    // }
//     if(isValue == false) cout << "0\n";
//     else cout << result << "\n";
    
// }