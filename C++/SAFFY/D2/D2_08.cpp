// 1984

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int sum = 0;
        int max_num = 0;
        int min_num = 10000;

        int cnt = 10;
        while(cnt--){
            int num;
            cin >> num;

            sum += num;
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }

        float result = (sum - max_num - min_num) / 8.0;
        
        cout << "#" << test_case << " " << round(result) << "\n";
    }   
    return 0;
}