// 1204

#include<bits/stdc++.h>

using namespace std;

int score_arr[105];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int num;
        cin >> num;

        memset(score_arr, 0, sizeof(score_arr));
        
        int ans = 101;
        for(int i=0; i<1000; i++){
            int n;
            cin >> n;

            score_arr[n]++;
            if(score_arr[ans] < score_arr[n]) ans = n;
            else if(score_arr[ans] == score_arr[n]){
                if(ans < n) ans = n;
            }

        }       

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}
