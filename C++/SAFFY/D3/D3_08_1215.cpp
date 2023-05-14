// 1215

#include<bits/stdc++.h>
 
using namespace std;
 
char arr[10][10];
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int T = 10;
 
    for(int test_case = 1; test_case <= T; test_case++){
 
        int user_input;
        cin >> user_input;
 
        int ans;
 
        for(int i=0; i < 8; i++){
            for(int j=0; j < 8; j++){
                cin >> arr[i][j];
            }
        }
 
        int cnt = 0;
        int pos = user_input / 2;
 
        if(user_input % 2 == 0){
            for(int i= 0; i < 8; i++){
                for(int j= pos; j <= 8-pos; j++){
                    for(int k=1; k <= pos; k++){
                        if(arr[i][j+k-1] != arr[i][j-k])
                            break;
                        if(k == pos) cnt++;
                    }
                }
            }
            for(int i= 0; i< 8; i++){
                for(int j= pos; j <= 8-pos; j++){
                    for(int k=1; k <= pos; k++){
                        if(arr[j+k-1][i] != arr[j-k][i])
                            break;
                        if(k == pos) cnt++;
                    }
                }
            }
        }
        else{
            for(int i= 0; i < 8; i++){
                for(int j= pos; j <= 8-pos; j++){
                    for(int k=1; k <= pos; k++){
                        if(arr[i][j+k] != arr[i][j-k])
                            break;
                        if(k == pos) cnt++;
                    }
                }
            }
            for(int i= 0; i< 8; i++){
                for(int j= pos; j <= 8-pos; j++){
                    for(int k=1; k <= pos; k++){
                        if(arr[j+k][i] != arr[j-k][i])
                            break;
                        if(k == pos) cnt++;
                    }
                }
            }
        }
 
        cout << "#" << test_case << " " << cnt << "\n";
    }
 
    return 0;
}

/*
int solve(int l)
{
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<=N-l; j++) {
            int flag=1;
            for (int k=0; k<l/2; k++) {
                if (G[i][j+k] != G[i][j+l-1-k]) {
                    flag = 0; break;
                }
            }
            if (flag) cnt++;
            flag=1;
            for (int k=0; k<l/2; k++) {
                if (G[j+k][i] != G[j+l-1-k][i]) {
                    flag = 0; break;
                }
            }
            if (flag) cnt++;
        }
    }
 
    return cnt;
}
*/