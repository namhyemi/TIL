// 2025

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int sum = n;
    while(n--){
        sum += n;
    }
    cout << sum << "\n";

    return 0;
}