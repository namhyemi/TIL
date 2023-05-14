// 1966

#include<bits/stdc++.h>

using namespace std;

int arr[55];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int cnt;
        cin >> cnt;

        for(int i=0; i<cnt; i++){
            cin >> arr[i];
        }

        sort(arr, arr+cnt);

        cout << "#" << test_case << " ";
        for(int i=0; i<cnt; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
