// https://www.acmicpc.net/problem/16401
// 16401. ���� �����ֱ�

// �ٽ� Ǯ��

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> snack; 

bool solve(int x){
    if(x == 0) return true;
    ll cur = 0;
    for(int i = 0; i < m; i++) cur += snack[i] / x;
    return cur >= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    int a;
    for(int i=0; i<m; i++){ cin >> a; snack.push_back(a); }

    int st = 0;
    int en = *max_element(snack.begin(), snack.end());

    while(st < en){
        int mid = (st+en+1)/2;

        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st << "\n";    
}

// Ʋ�� ���� : st = 1;

//https://www.acmicpc.net/blog/view/109