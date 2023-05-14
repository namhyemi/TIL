// 1970

#include<bits/stdc++.h>

using namespace std;

int money_arr[15] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
int result_arr[15];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int money;
        cin >> money;

        memset(result_arr, 0, sizeof(result_arr));
        for(int i=0; i < 8; i++){
            if(money_arr[i] <= money)
            result_arr[i] = money / money_arr[i];
            money %= money_arr[i];
        }
    
        cout << "#" << test_case << "\n";
        for(int i=0; i < 8; i++){cout << result_arr[i] << " ";}
        cout << "\n";
    }
    return 0;
}
