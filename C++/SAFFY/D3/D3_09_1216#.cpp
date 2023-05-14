// 1216

#include<bits/stdc++.h>

#define MAX 100

using namespace std;

char arr[105][105];
int ans;


void ResetData(){
    ans = 1;
    memset(arr, 0, sizeof(arr));
}

void InputData(){
    int num;
    cin >> num;

    for(int i=0; i < MAX; i++){
        for(int j=0; j < MAX; j++){
            cin >> arr[i][j];
        }
    }
}

void CheckHorizontal(int x, int y, int l){

    bool flag = false;
    int sx = x, sy = y, ex = x, ey = y + (l - 1);
    
    while(1){
        if(sy > ey){
            flag = true;
            break;
        }

        if(arr[sx][sy] == arr[ex][ey]){
            sy++;
            ey--;
        }
        else break;
    }

    if(flag == true) ans = max(ans, l);
}

void CheckVertical(int x, int y, int l){

    bool flag = false;
    int sx = x, sy = y, ex = x + (l-1), ey = y;

    while(1){
        if(sx > ex){
            flag = true;
            break;
        }

        if(arr[sx][sy] == arr[ex][ey]){
            sx++;
            ex--;
        }
        else break;
    } 

    if(flag == true) ans = max(ans, l);
}

void CheckData(){
    for(int i=0; i < MAX; i++){
        for(int j=0; j < MAX; j++){
            for(int k = 2; k < MAX; k++){
                if(j+k <= MAX) CheckHorizontal(i, j, k);
                if(i+k <= MAX) CheckVertical(i, j, k);
            }
        }
    }
}

void Solve(){

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        ResetData();
        InputData();
        CheckData();

        cout << "#" << test_case << " " << ans << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    Solve();

    return 0;
}
