// 2005

#include<bits/stdc++.h>

using namespace std;

int arr[15][15];

int main(int argc, char **argv){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i=1; i<=10; i++){
        for(int j=1; j <= i; j++){
            if(j==1 || j==i) arr[i][j] = 1;
            else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    for(int test_case = 1; test_case <= T; test_case++){
        int num;
        cin >> num;

        cout << "#" << test_case << "\n";
        for(int i=1; i<=num; i++){
            for(int j=1; j<=i; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }   
    return 0;
}