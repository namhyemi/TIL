// https://www.acmicpc.net/problem/5397
// 5397번. 키로거

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    while(num--)
    {
        list<char> L = {};
        list<char>::iterator t = L.begin();
        string str;

        cin >> str;
        for(auto s: str)
        {
            if(s == '<')
            {
                if(t != L.begin()) t--;
            }
            else if(s == '>')
            {
                if(t != L.end()) t++;
            }
            else if(s == '-')
            {
                if(t != L.begin())
                {
                    t--;
                    t = L.erase(t);
                }
            }
            else L.insert(t, s);
        }

        for(auto it : L) cout << it;
        cout << "\n";
    }
}