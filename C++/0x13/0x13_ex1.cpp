// https://www.acmicpc.net/problem/1920
// 1920. 수 찾기

#include<bits/stdc++.h>

using namespace std;

int A[100005];
int n;

int BinarySearch(int target){
    int st = 0;
    int ed = n-1;

    while(st <= ed){
        int mid = (st+ed)/2;

        if(target > A[mid]){
            st = mid+1;
        }
        else if(target < A[mid]){
            ed = mid-1;
        }
        else 
            return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; i++){ cin >> A[i]; }
    
    sort(A, A+n);

    int m;
    cin >> m;
    while(m--){
        int t;
        cin >> t;
        cout << BinarySearch(t) << "\n";
    } 
}

// STL : binary_search(a, a+n, t) or binary_search(a.begin(), a.end(), target)
// 시간 복잡도 : O(NlogN + MlogN) - NlogN 정렬 / MlogN 이분탐색
