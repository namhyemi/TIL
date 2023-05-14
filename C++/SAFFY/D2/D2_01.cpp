// 1859
#include<bits/stdc++.h>

using namespace std;

int money_arr[1000005];

int main(int argc, char **argv){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){

        int day;
        cin >> day;

        for(int i=1; i <= day; i++){
            cin >> money_arr[i];
        }

        int max_money = 0;
        long long sum = 0;

        for(int i=day; i > 0; i--){
            if(max_money > money_arr[i]){
                sum += max_money - money_arr[i];
            }    
            else{
                max_money = money_arr[i];
            }
        }
        cout << "#" << test_case << " " << sum << "\n";
    }   

    return 0;
}
