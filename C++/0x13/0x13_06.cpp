// https://www.acmicpc.net/problem/2467
// 2467. 용액

// 다시 풀기

#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num;
    for(int i=0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }

    int minus_result = 1000000000, plus_result = 1000000000;
    for(auto data: arr){
        int st = 0;
        int en = arr.size() - 1;   

        while(st < en){
            int mid = (st+en+1) / 2;

            if(data + arr[mid] > 0) en = mid-1;
            else if(data + arr[mid] <= 0) st = mid;
        }
        
        if(abs(data + arr[st]) < abs(minus_result + plus_result)){
            minus_result = data;
            plus_result = arr[st];
        }
    }

    cout << minus_result << " " << plus_result << "\n";
}

// 같은 용액 두번 사용에 대한 제외가 필요

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005];

int ans1 = 1e9+5;
int ans2 = 1e9+5;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> a[i];
    int st = 0;
    int en = N-1;
    while(st < en){
        if(abs(ans1+ans2) > abs(a[st]+a[en])){
        ans1 = a[st];
        ans2 = a[en];
        }
        if(abs(a[st] + a[en-1]) <= abs(a[st+1] + a[en])) en = en - 1;
        else st = st + 1;
    }
    cout << ans1 << " " << ans2;
}
*/