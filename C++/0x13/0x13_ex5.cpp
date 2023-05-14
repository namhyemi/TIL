// https://www.acmicpc.net/problem/1654
// 1654. 랜선 자르기

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int k, n;
int arr[10005];

bool solve(ll x){
    ll cur = 0;
    for(int i = 0; i < k; i++) cur += arr[i] / x;
    return cur >= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    
    for(int i=0; i < k; i++) cin >> arr[i];

    ll st = 1;
    ll en = 0x7fffffff; // 2^31 - 1

    while(st < en){
        ll mid = (st+en+1)/2;

        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}

// Parametric Search : 조건을 만족하는 최소/최댓값을 구하는 문제(최적화 문제)를 결정 문제로 변환해 이분 탐색을 수행하는 방법

// (최적화 문제) N개를 만들 수 있는 랜선의 최대 길이
// (결정 문제) 랜선의 길이가 X 일 때 랜선이 N개 이상인가 아닌가? -> 이분 탐색은 감소함수, 증가함수인 경우

// O(log(2^31)K) = O(31K)

// mid = (st+en)/2 하면 무한 루프에 빠짐
