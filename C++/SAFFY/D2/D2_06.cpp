// 1989

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        string str;
        cin >> str;

        bool check = 1;
        for(int i=0; i<str.length()/2; i++){
            if(str[i] != str[str.length()-1-i]){
                check = 0;
                break;
            }
        }
        cout << "#" << test_case << " " << check << "\n";
    }   
    return 0;
}

