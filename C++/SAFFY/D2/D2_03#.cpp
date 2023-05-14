//2007

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
 
        for(int i=1; i <= 15; i++){
            bool check = 0;
            string str1 = str.substr(0,i);
            for(int j=i; j < 30-i; j+=i){
                string str2 = str.substr(j,i);
                if(str1.compare(str2) != 0){
                    check = 0;
                    break;
                }
                else{
                    check = 1;
                }
            }
            if(check == 1){
                cout << "#" << test_case << " " << i << "\n";
                break;
            }
        }
    }   
    return 0;
}