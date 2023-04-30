// https://www.acmicpc.net/problem/14501
// 14501��. ���

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

        if(days - cur < today){ // ���� ���Ϻ��� �Ⱓ�� �� ���
            for(int b = 0; b < cur; b++){
                if(schedule[b].X > 0){ schedule[b].X -= 1; } // ���� ����
            }
            continue;
        }

        else{
            for(int b = 0; b < cur; b++){
                if(schedule[b].X > 0){ schedule[b].X -= 1; } // ���� ����

                if(schedule[b].X == 0){ // ��� �Ϸ�
                    if(schedule[cur].Y < schedule[b].Y + money){ // �� �ݾ��� ���� ū �������� �ݾ� ����
                        schedule[cur].Y = schedule[b].Y + money;
                    }
                }
            }
            max_money = max(max_money, schedule[cur].Y);
        }


    }
    cout << max_money << "\n";
}

// Ʋ�� ���� : ��� (���� ������ �� ��쿡�� ���� ���� ���� �ʿ�)

// N�� �ִ� 15 �̱� ������ O(N^2) ����