// https://www.acmicpc.net/problem/1931
// 1931번. 회의실 배정

// 반례 미확인

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int cnt;
int result=1;
int Timetable[100000];
vector<pair<int,int>> schedules;

void InputUserData(){
    cin >> cnt;
    int start, end;
    for(int i=0; i<cnt; i++){
        cin >> start >> end;
        schedules.push_back({start,end});
    }

}

bool Cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second != b.first) return a.second < b.second;
    return a.first < b.first;
}

void SchedulesSort(){
    sort(schedules.begin(), schedules.end(), Cmp);
}

void Calculator(){
    bool last = 1;
    int check=1;
    while(last){
        for(int j=Timetable[result-1]+1; j < cnt; j++){ // schedules
            check = j;
            if(schedules[j].X >= schedules[Timetable[result-1]].Y){
                Timetable[result] = j;
                result++;
                break;
            }
        }
        if(check == cnt-1) last = 0;
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



