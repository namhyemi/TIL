// 1940

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int cnt;
        cin >> cnt;

        int km = 0;
        int sum = 0;
        for(int i=0; i<cnt; i++){
            int command, num;
            cin >> command;

            if(command==1){
                cin >> num;
                km += num;
                sum += km;
            } 
            else if(command==2){
                cin >> num;
                if(km-num > 0){
                    km -= num;
                }
                else km = 0;
                sum += km;
            }
            else{ // n==0
                sum += km;
            }
        }
        cout << "#" << test_case << " " << sum << "\n";

    }
    return 0;
}