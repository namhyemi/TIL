// 1961

#include<bits/stdc++.h>

using namespace std;

int arr[10][10];
string result[10][5];

void Rotation(int N){
    int tmp_arr[10][10];

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            tmp_arr[i][j] = arr[N-1-j][i];
        }
    }

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            arr[i][j] = tmp_arr[i][j];
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){

        memset(arr, 0, sizeof(arr));
        memset(result, 0, sizeof(result));

        int num;
        cin >> num;
        for(int i=0; i < num; i++){
            for(int j=0; j < num; j++){
                cin >> arr[i][j];
            }
        }        

        for(int i=0; i < 3; i++){
            Rotation(num);
            for(int j=0; j < num; j++){
                for(int k = 0; k < num; k++){
                    result[j][i] += to_string(arr[j][k]);
                }
            }
        }

        cout << "#" << test_case << "\n";
        for(int i=0; i < num; i++){
            for(int j=0; j < 3; j++){
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}


/*
#include<bits/stdc++.h>

using namespace std;

int arr[10][10];
int result[10][5];

void Rotation(int N){
    int tmp_arr[10][10];

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            tmp_arr[i][j] = arr[N-1-j][i];
        }
    }
    memmove(arr, tmp_arr, sizeof(arr));
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){

        memset(arr, 0, sizeof(arr));
        memset(result, 0, sizeof(result));

        int num;
        cin >> num;
        for(int i=0; i < num; i++){
            for(int j=0; j < num; j++){
                cin >> arr[i][j];
            }
        }        

        for(int i=0; i < 3; i++){
            Rotation(num);
            for(int j=0; j < num; j++){
                for(int k = 0; k < num; k++){
                    result[j][i] *= 10;
                    result[j][i] += arr[j][k];
                }
            }
        }

        cout << "#" << test_case << "\n";
        for(int i=0; i < num; i++){
            for(int j=0; j < 3; j++){
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
*/

/*
using namespace std;
 
int input[8][8];
int N;
 
void calc()
{
    for(int i=0; i<N; i++)
    {
        for(int j=N-1; j>=0; j--)
            printf("%d", input[j][i]);
        printf(" ");
        for(int j=N-1; j>=0; j--)
            printf("%d", input[N-(i+1)][j]);
        printf(" ");
        for(int j=0; j<N; j++)
            printf("%d", input[j][N-(i+1)]);
        printf(" ");
        printf("\n");
    }
}
 
int main()
{
    int T; scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                scanf("%d", &input[i][j]);
        }
        printf("#%d \n", i);
        calc();
    }
}
*/