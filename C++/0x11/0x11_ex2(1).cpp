// https://www.acmicpc.net/problem/1931
// 1931��. ȸ�ǽ� ����

// ����

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
        if(cur_time > schedules[i].second) continue; // ���۽ð� ��
        result++;
        cur_time = schedules[i].first; // ������ �ð� ���
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



