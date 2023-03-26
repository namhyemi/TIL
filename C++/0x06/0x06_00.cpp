// https://www.acmicpc.net/problem/10845
// 10845번. 큐

// STL queue 사용

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int num;

    cin >> num;
    while(num--)
    {
        int i;
        string str;
        cin >> str;

        if(str == "push")
        {
            cin >> i;
            Q.push(i);
        }
        else if(str == "pop")
        {
            if(!Q.empty())
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
            else cout << "-1\n";
        }
        else if(str == "front")
        {
            if(!Q.empty())
            {   
                cout<< Q.front() << "\n";
            }
            else cout << "-1\n";
        }
        else if(str == "back")
        {
            if(!Q.empty()) cout << Q.back() << "\n";
            else cout << "-1\n";
        }
        else if(str == "empty")
        {
            if(Q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(str == "size")
        {
            cout << Q.size() << "\n";
        }
        else ;
    }
}