// https://www.acmicpc.net/problem/2457
// 2457��. ���ִ��� ����

// �ٽ� Ǯ��

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int arr[1005];

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> flower;
    for (int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm * 100 + sd, em * 100 + ed}); // ��¥�� ���� �Ľ��ص� ��
    }

    int t = 301; // ���� �ð�
    int ans = 0; // ������ ���� ����
    while (t < 1201) {
        int nxt_t = t; // �̹��� �߰��� ������ ���� ����� �ð�
        for(int i = 0; i < n; i++){
        if(flower[i].X <= t && flower[i].Y > nxt_t)
            nxt_t = flower[i].Y;
        }
        if(nxt_t == t){ // �ð� t���� �� ������ �Ұ���
        cout << 0;
        return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans;
}