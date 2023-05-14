// 1209

#include<bits/stdc++.h>

using namespace std;

int arr[105][105];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        int cnt;
        cin >> cnt;

        int sum = 0;
        int max_sum = 0;
        for(int i=0; i < 100 ; i++){
            sum = 0;
            for(int j=0; j < 100; j++){
                cin >> arr[i][j];
                sum += arr[i][j];
            }
            max_sum = max(max_sum, sum);
        }

        for(int i=0; i < 100 ; i++){
            sum = 0;
            for(int j=0; j < 100; j++){
                sum += arr[j][i];
            }
            max_sum = max(max_sum, sum);
        }

        sum = 0;
        for(int i=0; i < 100; i++){
            sum += arr[i][i];
        }
        max_sum = max(max_sum, sum);

        sum = 0;
        for(int i=0; i < 100; i++){
            sum += arr[i][100-1-i];
        }
        max_sum = max(max_sum, sum);

        cout << "#" << test_case << " " << max_sum << "\n";
    }

    return 0;
}