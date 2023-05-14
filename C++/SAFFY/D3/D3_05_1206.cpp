// 1206

#include<bits/stdc++.h>

using namespace std;

int arr[1005];
int dx[4] = {-2,-1,1,2};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        int cnt;
        cin >> cnt;

        memset(arr, 0, sizeof(arr));

        for(int i=2; i<=cnt+1; i++){
            cin >> arr[i];
        }

        int ans = 0;
        for(int i=2; i<=cnt+1; i++){
            int max_num = 0;
            for(int j=0; j<4; j++){
                max_num = max(max_num, arr[i+dx[j]]);
            }
            
            if(arr[i] > max_num){
                ans += (arr[i] - max_num);
            }
        }
        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}