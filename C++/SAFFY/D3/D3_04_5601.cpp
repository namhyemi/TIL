// 5601

#include<bits/stdc++.h>

using namespace std;

int arr[10005];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){

        int cnt;
        cin >> cnt;

        cout << "#" << test_case << " ";
        for(int i=1; i<=cnt; i++){
            cout << "1/" << cnt << " ";
        }
        cout << "\n";
    }

    return 0;
}