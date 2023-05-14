// 1208

#include<bits/stdc++.h>

using namespace std;

int arr[105];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        int cnt;
        cin >> cnt;

        memset(arr, 0, sizeof(arr));

        int num;
        for(int i=0; i<100; i++){
            cin >> num;
            arr[num]++;
        }

        int ans = 0;
        int min_pos = 0;
        int max_pos = 100;
        for(int i=0; i<cnt; i++){
            while(!arr[min_pos]){
                min_pos++;
            }
            while(!arr[max_pos]){
                max_pos--;
            }

            if(min_pos == max_pos || max_pos - min_pos == 1){
                break;
            }

            arr[min_pos]--;
            arr[min_pos+1]++;

            arr[max_pos]--;
            arr[max_pos-1]++;
        }

        while(!arr[min_pos]){
            min_pos++;
        }
        while(!arr[max_pos]){
            max_pos--;
        }

        cout << "#" << test_case << " " << max_pos - min_pos << "\n";
    }

    return 0;
}