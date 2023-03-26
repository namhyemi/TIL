// https://www.acmicpc.net/problem/10866
// 10866번. 덱

// 직접 구현(배열 사용)

#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            push_front(i);
        }
        else if(str == "push_back")
        {
            cin >> i;
            push_back(i);
        }
        else if(str == "pop_front")
        {
            if(head != tail)
            {
                cout << front() << "\n";
                pop_front();
            }
            else cout << "-1\n"; 
        }
        else if(str == "pop_back")
        {
            if(head != tail)
            {
                cout << back() << "\n";
                pop_back();
            }
            else cout << "-1\n"; 
        }
        else if(str == "size")
        {
            cout << tail-head << "\n";
        }
        else if(str == "empty")
        {
            if(head == tail) cout << "1\n";
            else cout << "0\n";
        }
        else if(str == "front")
        {
            if(head != tail)
            {
                cout << front() << "\n";
            }
            else cout << "-1\n";
        } 
        else if(str == "back")
        {
            if(head != tail)
            {
                cout << back() << "\n";
            }
            else cout << "-1\n";
        } 
    }
}