// https://www.acmicpc.net/problem/15486
// 15486��. ���2

#include <bits/stdc++.h>

using namespace std;

int schedule[1500055]; // ���� �����ٱ��� �� ���� ū �ݾ�

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int last_day;
    cin >> last_day;

    int day, money;
    int max_money = 0;
    for(int cur = 0; cur < last_day; cur++){
        cin >> day >> money;

        max_money = max(schedule[cur], max_money); // ���ñ��� ���� �ݾ��� Ȯ���ؼ� �� ū �ݾ� ����

        schedule[cur+day] = max(schedule[cur+day], max_money + money); // ���� ���� �������� ������ �Ǵ³� �ݾ� ����     
    }
    cout << max(max_money, schedule[last_day]);
}
