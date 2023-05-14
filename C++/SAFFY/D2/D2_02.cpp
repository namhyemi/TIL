// 1926
#include<bits/stdc++.h>

using namespace std;

int money_arr[1000005];

int main(int argc, char **argv){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        int num = test_case;

        int check = 0;
        while(num){
            int remain = num % 10;
            if(remain == 3 || remain == 6 || remain == 9){ check++; }

            num /= 10;
        }

        if(check == 0) cout << test_case << " ";
        else{
            while(check){
                cout << "-";
                check--;
            }
            cout << " ";
        }
    }   

    return 0;
}
