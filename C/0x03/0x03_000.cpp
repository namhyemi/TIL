// https://www.acmicpc.net/problem/10808
// ���ĺ� ����

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

// ASCII �˻� 
// String �Լ� �˻�

// �迭 ������ �����ϸ� �ڵ����� 0���� �ʱ�ȭ
//   string s;
//   cin >> s;
//   for(auto c : s)
//     freq[c-'a']++;