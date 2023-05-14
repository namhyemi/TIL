// https://www.acmicpc.net/problem/10815
// 10815. 숫자 카드

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){ cin >> arr[i]; }
    sort(arr, arr+n);

    int m;
    cin >> m;
    while(m--){
        int num;
        cin >> num;

        cout << binary_search(arr, arr+n, num) << " ";
    }
}