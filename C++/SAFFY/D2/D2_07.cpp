// 1986

#include<bits/stdc++.h>

using namespace std;

int arr[15];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int i=1; i<=10; i++){
        if(i%2 == 0) arr[i] = arr[i-1] - i;
        else arr[i] = arr[i-1] + i;
    }


    for(int test_case = 1; test_case <= T; test_case++){
        int num;
        cin >> num;

        cout << "#" << test_case << " " << arr[num] << "\n";
    }   
    return 0;
}

