// 1948

#include<bits/stdc++.h>

using namespace std;

int month_arr[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int st_m, st_d, en_m, en_d;
        cin >> st_m >> st_d >> en_m >> en_d;

        int result = 0;

        if(st_m == en_m){
            result += (en_d - st_d + 1);
        }
        else{
            result += month_arr[st_m] - st_d + 1;
            result += en_d;
        }

        for(int i = st_m+1; i < en_m; i++){
            result += month_arr[i];
        }

        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;
}
