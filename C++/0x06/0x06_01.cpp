// https://www.acmicpc.net/problem/10845
// 10845번. 큐

// 직접 구현 

#include<bits/stdc++.h>

using namespace std;

int dat[100005];
int head=0, tail=0;

void push(int x)
{
    dat[tail++] = x;
}

void pop()
{
    head++;
}

int front()
{
    return dat[head];
}

int back()
{
    return dat[tail-1];
}


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
            push(i);
        }
        else if(str == "pop")
        {
            if(head != tail)
            {
                cout << front() << "\n";
                pop();
            }
            else cout << "-1\n";
        }
        else if(str == "front")
        {
            if(head != tail) cout << front() << "\n";
            else cout << "-1\n";
        }
        else if(str == "back")
        {
            if(head != tail) cout << back() << "\n";
            else cout << "-1\n";
        }
        else if(str == "empty")
        {
            if(head != tail) cout << "0\n";
            else cout << "1\n";
        }
        else if(str == "size")
        {
            cout << tail-head << "\n";
        }
        else ;
    }
    cout << "\n";
}