// https://www.acmicpc.net/problem/2467
// 2467. ���

// �ٽ� Ǯ��

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans1 = 1e9+1;
    int ans2 = 1e9+1;
    for(int i = 0; i < n; i++){ // -a[i]�� ���� lower_bound�� ���� ����
        int idx = lower_bound(a, a+n, -a[i]) - a; // lower_bound�� ������ ���� a[idx]�� -a[i]�� ���ų�, -a[i]���� ū ���� �߿� ���� ���� �����̴�.
        // a[i]�� ������ �� ���� ���� ���� ���Ҵ� a[idx+1] Ȥ�� a[idx] Ȥ�� a[idx-1]�̴�.
        if(idx+1 < n && i != idx+1 && abs(a[i] + a[idx+1]) < abs(ans1 + ans2)){
        ans1 = a[i];
        ans2 = a[idx+1];
        }
        if(idx < n && i != idx && abs(a[i] + a[idx]) < abs(ans1 + ans2)){
        ans1 = a[i];
        ans2 = a[idx];
        }
        if(idx != 0 && i != idx-1 && abs(a[i] + a[idx-1]) < abs(ans1 + ans2)){
        ans1 = a[i];
        ans2 = a[idx-1];
        }
    }
    if(ans1 > ans2) swap(ans1, ans2); // ��� ���Ŀ� �°� ����
    cout << ans1 << ' ' << ans2;
}

// https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x13/solutions/2467.cpp