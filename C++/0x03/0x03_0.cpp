// https://www.acmicpc.net/problem/10808
// 알파벳 개수

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[26];
    string str;

    cin >> str;
    fill(a,a+26,0);
    for(int i=0; i < str.length(); i++) a[str[i] - 97]++;
    for(int i=0; i < 26; i++) cout << a[i] << ' ';
    cout << '\n';
}

// ASCII 검색 
// String 함수 검색

// 배열 전역에 선언하면 자동으로 0으로 초기화
//   string s;
//   cin >> s;
//   for(auto c : s)
//     freq[c-'a']++;