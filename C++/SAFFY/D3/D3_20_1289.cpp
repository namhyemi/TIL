// 1289

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        string str;
        cin >> str;

        int ans = 0;
        bool flag = false;
        for(char c : str){
            if(c == '1'){
                if(flag == false){
                    ans++;
                    flag = true;
                }
            }
            if(c == '0'){
                if(flag == true){
                    ans++;
                    flag = false;
                }
            }
        }

        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}