// https://www.acmicpc.net/problem/11328
// 11328번. Strfry

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

// 삽질1 : for(int j=0; str.length(); j++)
// 종료 코드: 3221225477 -> 인덱스에 char 사용 (자동으로 아스키코드 값으로 변할거라 생각)
// 종료 코드: 1

// 틀린 이유 : result 값, 배열 초기화를 for문 밖에서 함.

// c++ 은 문자 선언을 맨 앞에서 해야하는가?  -> 사용하기 전에만 하면 됨 (C는 함수 가장 상단에 등장해야 함.)