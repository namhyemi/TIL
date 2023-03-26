// https://www.acmicpc.net/problem/10866
// 10866¹ø. µ¦

// STL deque »ç¿ë

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    int num;

    cin >> num;
    while(num--)
    {
        int i;
        string str;
        cin >> str;

        if(str == "push_front")
        {
            cin >> i;
            DQ.push_front(i);
        }
        else if(str == "push_back")
        {
            cin >> i;
            DQ.push_back(i);
        }
        else if(str == "pop_front")
        {
            if(!DQ.empty())
            {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
            else cout << "-1\n"; 
        }
        else if(str == "pop_back")
        {
            if(!DQ.empty())
            {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
            else cout << "-1\n"; 
        }
        else if(str == "size")
        {
            cout << DQ.size() << "\n";
        }
        else if(str == "empty")
        {
            if(DQ.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(str == "front")
        {
            if(!DQ.empty())
            {
                cout << DQ.front() << "\n";
            }
            else cout << "-1\n";
        } 
        else if(str == "back")
        {
            if(!DQ.empty())
            {
                cout << DQ.back() << "\n";
            }
            else cout << "-1\n";
        } 
    }
}