// 2005

#include<bits/stdc++.h>

using namespace std;

int arr[20][20];

int main(int argc, char **argv){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        int N, M;
        cin >> N >> M;

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> arr[i][j];
            }
        }

        int max_sum = 0;
        for(int i=1; i<=N-M+1; i++){
            for(int j=1; j<=N-M+1; j++){
                int sum = 0;
                for(int sum_i=0; sum_i<M; sum_i++){
                    for(int sum_j=0; sum_j<M; sum_j++){
                        sum += arr[i+sum_i][j+sum_j];
                    }
                }
                max_sum = max(sum, max_sum);
            }
        }
        cout << "#" << test_case << " " << max_sum << "\n";       
    }   
    return 0;
}


/*
2차원 배열 누적합 

#include<bits/stdc++.h>

using namespace std;

int arr[20][20];

int main(int argc, char **argv){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        int N, M;
        cin >> N >> M;

        memset(arr, 0, sizeof(arr));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> arr[i][j];
                arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            }
        }

        int max_sum = 0;
        for(int i=1; i+M-1 <= N; i++){
            for(int j=1; j+M-1 <= N; j++){
                max_sum = max(sum, arr[i+M-1][j+M-1]-arr[i+M-1][j-1]-arr[i-1][j+M-1]+arr[i-1][j-1]);
            }
        }
        cout << "#" << test_case << " " << max_sum << "\n";
    }   
    return 0;
}

*/