// 1285

#include<bits/stdc++.h>

using namespace std;

int num[10];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int cnt;
        cin >> cnt;

        int ans = 100000;
        int ans_people = 0;
        for(int i=0; i<cnt; i++){
            int num;
            cin >> num;

            if(ans > abs(0+num)){
                ans = abs(0+num);
                ans_people = 1;
            }
            else if(ans == abs(0+num)){
                ans_people++;
            }
        }

        cout << "#" << test_case << " " << ans << " " << ans_people << "\n";
    }
    return 0;
}
