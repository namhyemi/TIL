// 1220

#include<bits/stdc++.h>

using namespace std;

int ans;
int arr[105][105];

void InputData(int num){
    for(int i=0; i < num; i++){
        for(int j=0; j < num; j++){
            cin >> arr[i][j];
        }
    }
}

void CheckData(int num){
    for(int i = 0; i < num; i++){
        bool check = false;
        for(int j = 0; j < num; j++){
            if(arr[j][i] == 1){
                if(check == false){
                    check = true;
                }
            }
            else if(arr[j][i] == 2){
                if(check == true){
                    ans++;
                    check = false;
                }
            }   
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;
    for(int test_case = 1; test_case <= T; test_case++){
        
        int num;
        cin >> num;

        ans = 0;

        InputData(num);
        CheckData(num);

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}
