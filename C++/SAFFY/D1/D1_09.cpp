// 2047

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for(char s : str){
        if(s >= 'a' && s <= 'z')
            cout << char(s - 'a' + 'A');
        else cout << s;
    }
}