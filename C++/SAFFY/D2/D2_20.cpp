// 1945

#include<bits/stdc++.h>

using namespace std;

int arr[5] = {2,3,5,7,11};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int num;
        cin >> num;

        cout << "#" << test_case << " ";
        for(int i=0; i<5; i++){
            int n = 0;
            while(num % arr[i] == 0){
                num /= arr[i];
                n++;
            }
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;
}
