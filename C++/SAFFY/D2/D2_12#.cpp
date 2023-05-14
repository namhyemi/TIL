// 1974

#include<bits/stdc++.h>

using namespace std;

int arr[15][15];
int check[10];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                cin >> arr[i][j];
            }
        }

        bool flag = 1;
        for(int i=1; i<=9; i++){
            if(flag == 0){ break; }
            memset(check, 0, sizeof(check));
            for(int j=1; j<=9; j++){
                if(!check[arr[i][j]]) check[arr[i][j]]++;
                else{
                    flag = 0;
                    break;
                }
            }
            
        }

        for(int i=1; i<=9; i++){
            if(flag == 0){ break; }
            memset(check, 0, sizeof(check));
            for(int j=1; j<=9; j++){
                if(!check[arr[j][i]]) check[arr[j][i]]++;
                else{
                    flag = 0;
                    break;
                }
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(flag == 0){ break; }
                memset(check, 0, sizeof(check));
                for(int k=1; k<=3; k++){
                    for(int l=1; l<=3; l++){
                        if(!check[arr[i*3+k][j*3+l]]) check[arr[i*3+k][j*3+l]]++;
                        else{
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        
        cout << "#" << test_case << " " << flag << "\n";
    }
    return 0;
}

/*
https://algosu.tistory.com/26
*/