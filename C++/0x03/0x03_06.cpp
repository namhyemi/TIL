// https://www.acmicpc.net/problem/11328
// 11328��. Strfry

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, result;
    string str;

    cin >> num;
    for(int i=0; i < num; i++)
    {
        int a[26]={};
        result = 0;

        cin >> str;
        for(int j=0; j < str.length(); j++) a[str[j]-97]++;
        cin >> str;
        for(int j=0; j < str.length(); j++) a[str[j]-97]--;

        for(int j=0; j < 26 ; j++) if(a[j] != 0) result++;

        if(result!=0) cout << "Impossible" << "\n";
        else cout << "Possible" << "\n";
    }
}

// strcpy, strcmp, strtok, strlen, strcat 

// ����1 : for(int j=0; str.length(); j++)
// ���� �ڵ�: 3221225477 -> �ε����� char ��� (�ڵ����� �ƽ�Ű�ڵ� ������ ���ҰŶ� ����)
// ���� �ڵ�: 1

// Ʋ�� ���� : result ��, �迭 �ʱ�ȭ�� for�� �ۿ��� ��.

// c++ �� ���� ������ �� �տ��� �ؾ��ϴ°�?  -> ����ϱ� ������ �ϸ� �� (C�� �Լ� ���� ��ܿ� �����ؾ� ��.)