// 5642

#include<bits/stdc++.h>

using namespace std;

int main(){

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){

        int cnt;
        cin >> cnt;

        int max_sum = -10000;
        int sum = 0;
        for(int i = 0; i < cnt; i++){
            int num;
            cin >> num;

            sum += num;
            max_sum = max(sum, max_sum);

            if(sum < 0) sum = 0;   
        }

        cout << "#" << test_case << " " << max_sum << "\n";
    }
    
    return 0;
}