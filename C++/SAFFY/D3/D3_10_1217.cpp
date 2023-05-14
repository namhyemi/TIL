// 1217

#include<bits/stdc++.h>

using namespace std;

int N, M;

int func(int n){

    if(n==0) return 1;

    return func(n-1) * N;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;
    for(int test_case = 1; test_case <= T; test_case++){
        
        int num;
        cin >> num;

        cin >> N >> M;

        int ans = func(M);

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}
