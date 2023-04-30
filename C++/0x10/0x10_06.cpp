// https://www.acmicpc.net/problem/11055
// 11055��. ���� ū �����ϴ� �κ� ����

#include <bits/stdc++.h>

using namespace std;

int D[1005][2]; // [i][1] = �κ� ���� �� �� ���� ū �� [i][0] = ���� ���� ��

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int max_num = 0;
    for(int cur=1; cur<=n; cur++){ 
        cin >> D[cur][0];
        D[cur][1] = D[cur][0];
        for(int b=1; b < cur; b++){ 
            if(D[b][0] < D[cur][0]){ // if.�����ϴ� ��
                if(D[cur][1] < D[b][1] + D[cur][0]){ // if. �����ϴ� �κ� ���� �� ���� ���� ū �� ���� 
                    D[cur][1] = D[b][1] + D[cur][0];
                }
            }
        }
        if(D[cur][1] > max_num) max_num = D[cur][1]; // ���� ū ��
    }
    cout << max_num << "\n";
}

// Ʋ�� ���� : ��� (���� ������ ��쵵 ����)