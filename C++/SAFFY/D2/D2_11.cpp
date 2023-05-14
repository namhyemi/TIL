// 1976

#include<bits/stdc++.h>

using namespace std;

int arr[20][20];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int st_h, st_m, en_h, en_m;
        cin >> st_h >> st_m >> en_h >> en_m;

        int result_h = ((st_h + en_h) + (st_m + en_m) / 60) % 12; 
        int result_m = (st_m + en_m) % 60;

        if(result_h == 0) result_h = 12;
        cout << "#" << test_case << " " << result_h << " " << result_m << "\n";
    }
    return 0;
}
