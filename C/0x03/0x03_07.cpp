// https://www.acmicpc.net/problem/1919
// 1919번. 애너그램 만들기
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result=0, a[26]={};
    string s1, s2;

    cin >> s1 >> s2;

    for(auto s:s1) a[s-'a']++;
    for(auto s:s2) a[s-'a']--;

    for(int i:a)
    {
        if(i>0) result += i; 
        else if(i<0) result += -i;
    }

    cout << result << "\n";
}