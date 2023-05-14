// 2072

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    for(int j=1; j<=cnt; j++){
        int sum = 0;
        for(int i=1; i<=10; i++){
            int num;
            cin >> num;

            if(num % 2 != 0){
                sum += num;
            }
        }
        cout << "#" << j << " " << sum << "\n";
    }
}