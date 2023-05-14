// 1979

#include<bits/stdc++.h>

using namespace std;

int arr[20][20];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int N, K;
        cin >> N >> K;

        memset(arr, 0, sizeof(arr));

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> arr[i][j];
            }
        }

        int check = 0;
        for(int i=1; i<=N+1; i++){
            int len = 0;
            for(int j=1; j<=N+1; j++){
                if(arr[i][j] == 1) len++;
                else{
                    if(len == K){check++;}
                    len = 0;
                }
            }
        }
        for(int i=1; i<=N+1; i++){
            int len = 0;
            for(int j=1; j<=N+1; j++){
                if(arr[j][i] == 1) len++;
                else{
                    if(len == K){check++;}
                    len = 0;
                }
            }
        }

        cout << "#" << test_case << " " << check << "\n";
    }   
    return 0;
}
