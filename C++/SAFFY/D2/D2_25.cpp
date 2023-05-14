// 1284

#include<bits/stdc++.h>

using namespace std;

int num[10];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int P, Q, R, S, W;
        cin >> P >> Q >> R >> S >> W;

        int A_money = W * P;
        int B_money = Q;;
        if(W > R) B_money += (W-R) * S;

        int ans = min(A_money, B_money);

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}
