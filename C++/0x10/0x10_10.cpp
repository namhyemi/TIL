// https://www.acmicpc.net/problem/15486
// 15486번. 퇴사2

#include <bits/stdc++.h>

using namespace std;

int schedule[1500055]; // 현재 스케줄까지 중 가장 큰 금액

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int last_day;
    cin >> last_day;

    int day, money;
    int max_money = 0;
    for(int cur = 0; cur < last_day; cur++){
        cin >> day >> money;

        max_money = max(schedule[cur], max_money); // 오늘까지 잡힌 금액을 확인해서 더 큰 금액 저장

        schedule[cur+day] = max(schedule[cur+day], max_money + money); // 오늘 잡힌 스케쥴이 마무리 되는날 금액 저장     
    }
    cout << max(max_money, schedule[last_day]);
}
