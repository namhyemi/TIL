// https://www.acmicpc.net/problem/9095
// 9095��. 1,2,3 ���ϱ�

#include <bits/stdc++.h>

using namespace std;

int table[15]; // i �� 1,2,3�� ������ ��Ÿ���� ����� ��
int num;

void InputUserData(){
        cin >> num;
}

void TableDataReset(){
    table[1] = 1;
    table[2] = 2; 
    table[3] = 4;
}

void CalTable(){
    for(int i = 4; i <= num ; i++){
        table[i] = table[i-1] + table[i-2] + table[i-3];
    }
}

void OutputResultData(){
    cout << table[num] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt; 
    while(cnt--){
        InputUserData();
        TableDataReset();
        CalTable();
        OutputResultData();
    }
}


// ��Ʈ��ŷ
// 10�� for��

/*
�̸� �� ���س���
#include <bits/stdc++.h>

using namespace std;

int table[15]; // i �� 1,2,3�� ������ ��Ÿ���� ����� ��
int num;

void InputUserData(){
        cin >> num;
}

void TableDataReset(){
    table[1] = 1;
    table[2] = 2; 
    table[3] = 4;
}

void MakeTable(){
    TableDataReset();
    for(int i = 4; i <= 11 ; i++){
        table[i] = table[i-1] + table[i-2] + table[i-3];
    }
}

void OutputResultData(){
    cout << table[num] << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    MakeTable();

    int cnt;
    cin >> cnt; 
    while(cnt--){
        InputUserData();
        OutputResultData();
    }
}
*/