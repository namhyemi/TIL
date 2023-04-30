// https://www.acmicpc.net/problem/1931
// 1931��. ȸ�ǽ� ����

// �ݷ� ��Ȯ��

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

// �Ǽ� : �ٽ� ����ؾ� �ϴ� ������� �������� ����
// Ʋ�� ���� : ��ȣ(ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�.)


// �׸��� : task scheduling problem
// ���� : ���� �ð��� t��� �� �� ���� �ð��� t �̻��� ��� ȸ�� �߿��� ���� ���� ������ ȸ�Ǹ� ���ϴ� ���� �������̴�.


// 1. O(2^n) : ��� ������ ���� ��� Ȯ��
// 2. O(n^2) : ȸ�Ǹ� ������ �ð��� ���� ������, ������ �ð��� ���ٸ� ���� �ð��� ���� ������ ����
//             D[i] = i��° ȸ�Ǹ� ���������� �������� �� ȸ���� ��, D[i] = max(D[j]) + 1 (j��° ȸ���� ������ �ð��� i��° ȸ���� ���� �ð� ������ ��� j)



