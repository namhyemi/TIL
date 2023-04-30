// https://www.acmicpc.net/problem/1931
// 1931번. 회의실 배정

// 정답

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int cnt;
int result=0;
vector<pair<int,int>> schedules;

void InputUserData(){
    cin >> cnt;
    int start, end;
    for(int i=0; i<cnt; i++){
        cin >> start >> end;
        schedules.push_back({end,start});
    }
}

void SchedulesSort(){
    sort(schedules.begin(), schedules.end());
}

void Calculator(){
    int cur_time = 0;
    for(int i=0; i < cnt; i++){
        if(cur_time > schedules[i].second) continue; // 시작시간 비교
        result++;
        cur_time = schedules[i].first; // 끝나는 시간 기록
    }
}

void OutputResultData(){
    cout << result << "\n";
} 

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    SchedulesSort();
    Calculator();
    OutputResultData();
}

// 실수 : 다시 사용해야 하는 변수라면 후위연산 주의
// 틀린 이유 : 등호(회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.)


// 그리드 : task scheduling problem
// 명제 : 현재 시간이 t라고 할 때 시작 시간이 t 이상인 모든 회의 중에서 가장 먼저 끝나는 회의를 택하는 것이 최적해이다.


// 1. O(2^n) : 모든 가능한 배정 방법 확인
// 2. O(n^2) : 회의를 끝나는 시간이 빠른 순으로, 끝나는 시간이 같다면 시작 시간이 빠른 순으로 정렬
//             D[i] = i번째 회의를 마지막으로 진행했을 때 회의의 수, D[i] = max(D[j]) + 1 (j번째 회의의 끝나는 시간이 i번째 회의의 시작 시간 이하인 모든 j)



