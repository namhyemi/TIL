// https://www.acmicpc.net/problem/14501
// 14501번. 퇴사

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

vector<pair<int,int>> schedule;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int days;
    cin >> days;

    int today, money;
    int max_money = 0;
    for(int cur = 0; cur < days; cur++){
        cin >> today >> money;
        schedule.push_back({today, money}); 

        if(days - cur < today){ // 남은 요일보다 기간이 긴 경우
            for(int b = 0; b < cur; b++){
                if(schedule[b].X > 0){ schedule[b].X -= 1; } // 요일 감소
            }
            continue;
        }

        else{
            for(int b = 0; b < cur; b++){
                if(schedule[b].X > 0){ schedule[b].X -= 1; } // 요일 감소

                if(schedule[b].X == 0){ // 상담 완료
                    if(schedule[cur].Y < schedule[b].Y + money){ // 총 금액이 가장 큰 스케쥴의 금액 저장
                        schedule[cur].Y = schedule[b].Y + money;
                    }
                }
            }
            max_money = max(max_money, schedule[cur].Y);
        }


    }
    cout << max_money << "\n";
}

// 틀린 이유 : 계산 (남은 요일이 긴 경우에도 요일 감소 연산 필요)

// N이 최대 15 이기 때문에 O(N^2) 가능