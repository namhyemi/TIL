// 5603

#include<bits/stdc++.h>

using namespace std;

int arr[10005];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){

        int cnt;
        cin >> cnt;
        
        memset(arr, 0, sizeof(arr));

        int sum = 0;
        for(int i=0; i<cnt; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        
        sort(arr, arr+cnt);

        int avg = sum / cnt;
        int ans = 0;
        for(int i=0; i < cnt; i++){
            if(arr[i] > avg) break;
            ans += (avg - arr[i]);
        }
        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}