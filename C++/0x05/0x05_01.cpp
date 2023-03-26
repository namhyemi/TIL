// https://www.acmicpc.net/problem/10828
// 10828번. 스택

#include <bits/stdc++.h>
using namespace std;

//////// 직접 구현

int dat[100005];
int pos=0;

void push(int num)
{
    dat[pos++] = num;
}

int pop()
{
    if(pos==0) return -1;
    return dat[--pos]; 
}

int top()
{
    if(pos==0) return -1;
    return dat[pos-1];
}

int size()
{
    return pos;
}

int empty()
{
    if(pos > 0) return 0;
    else return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int num, a;

    cin >> num;
    while(num--)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> a;
            push(a);
        }
        else if(str == "pop") cout << pop() << "\n";
        else if(str == "top") cout << top() << "\n";
        else if(str == "empty") cout << empty() << "\n";
        else if(str == "size") cout << size() << "\n";
        else ;
    }
}


//////// STL stack 사용

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     stack<int> s;

//     string str;
//     int num, a;

//     cin >> num;

//     while(num--)
//     {
//         cin >> str;
//         if(str == "push")
//         {
//             cin >> a;
//             s.push(a);
//         }
//         else if(str == "pop")
//         {
//             if(s.empty()) cout << -1 << "\n";
//             else
//             {
//                 cout << s.top() << "\n";
//                 s.pop();
//             }
//         }
//         else if(str == "top")
//         {
//             if(s.empty()) cout << -1 << "\n";
//             else cout << s.top() << "\n" ;
//         }
//         else if(str == "size") cout << s.size() << "\n";
//         else if(str == "empty")
//         {
//             if(s.empty()) cout << 1 << "\n";
//             else cout << 0 << "\n";
//         }
//         else;
//     }
// }

