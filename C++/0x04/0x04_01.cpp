// https://www.acmicpc.net/problem/1406
// 1406번. 에디터

// STL ver
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> L = {};
    list<int>::iterator t = L.begin();

    string str;
    cin >> str;

    for(auto s : str)
    {
        L.push_back(s);
        t++;
    }
    t = L.end();

    int cnt;
    char a;
    cin >> cnt;
    for(int i=0;  i < cnt ; i++)
    {
        cin >> a;
        if(a == 'P')
        {
            cin >> a;
            L.insert(t, a);
        }
        else if(a == 'L')
        {
            if(t != L.begin()) t--;
        }
        else if(a == 'D')
        {
            if(t != L.end()) t++;
        }
        else if(a == 'B')
        {
            if(t == L.begin());
            else if(L.begin() != L.end()) 
            {
                t--;
                t = L.erase(t);
            }
            else;
        }  
        else ;

    }                                      

    for(auto it : L) cout << char(it);
//    for(list<int>::iterator it = L.begin() ; it != L.end() ; it++) cout << char(*it) << "\n"; (C++11 이하)
    cout << "\n";
}

// 결과값이 숫자(아스키코드)로 출력 -> char() 아니면 list<int> 대신 list<char> 사용
// L.end() 는 문자열 마지막 알파벳 그 다음(' ')



// 날림 연결 리스트

// const int MX = 1000005;
// char dat[MX]; 
// int pre[MX], nxt[MX];
// int unused = 1;

// void insert(int addr, char a)
// {
//     dat[unused] = a;
//     pre[unused] = addr;
//     nxt[unused] = nxt[addr];
//     if(nxt[addr] != -1) pre[nxt[addr]] = unused;
//     nxt[addr] = unused;
//     unused;
// }

// void erase(int addr)
// {
//     nxt[pre[addr]] = nxt[addr];
//     if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int cur=0, a;
//     char ch;
//     string str;


//     fill(pre, pre+MX, -1);
//     fill(nxt, nxt+MX, -1);

    
//     cin >> str;
//     for(auto s: str)
//     {
//         insert(cur, s);
//         cur++;
//     }

//     cin >> a;
//     while(a--)
//     {
//         cin >> str;

//         if(str == "L")
//         {
//             if(pre[cur] != -1) cur = pre[cur];
//         }
//         else if(str == "D")
//         {
//             if(pre[cur] != -1) cur = nxt[cur];
//         }
//         else if(str == "B")
//         {
//             if(pre[cur] != -1)
//             {
//                 erase(cur);
//                 cur = pre[cur];
//             }
//         }
//         else if(str == "P")
//         {
//             cin >> ch;
//             insert(cur, ch);
//             cur = nxt[cur];
//         }
//         else ;
//     }

//     cur = nxt[0];
//     while(cur != -1)
//     {
//         cout << char(dat[cur]);
//         cur = nxt[cur];
//     }

//     cout << "\n";
// }