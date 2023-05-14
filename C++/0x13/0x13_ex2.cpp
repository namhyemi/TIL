// https://www.acmicpc.net/problem/1920
// 1920. �� ã��

#include<bits/stdc++.h>

using namespace std;

int a[500005];

int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){ cin >> a[i]; }
    sort(a, a+n);

    int m;
    cin >> m;
    while(m--){
        int num;
        cin >> num;
        cout << upper_idx(num, n) - lower_idx(num, n) << " ";
    }
}

// STL : lower_bound(a, a+n, t) / upper_bound(a, a+n, t)