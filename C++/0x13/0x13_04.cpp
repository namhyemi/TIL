// https://www.acmicpc.net/problem/2805
// 2805. 나무 자르기

#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
vector<int> tree;

int solve(int x){
    ll cur = 0;
    for(int i=0; i<n; i++){
        if(tree[i] > x){
            cur += tree[i] - x;
        }
    }
    return cur >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int t;
    for(int i=0; i<n; i++){
        cin >> t;
        tree.push_back(t);
    }

    ll st = 0;
    ll en = *max_element(tree.begin(), tree.end());

    while(st < en){
        ll mid = (st + en + 1) / 2;

        if(solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st << "\n";
}

// 틀린 이유 : 자료형 
// 틀린 이유 : st = 1

