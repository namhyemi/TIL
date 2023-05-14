// https://www.acmicpc.net/problem/11653
// 11653. 소인수분해

#include<bits/stdc++.h>

using namespace std;

vector<int> result;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for(int i=2; i*i <= num; i++){
        while(num % i == 0){
            num /= i;
            result.push_back(i);
        }
    }
    if(num != 1) result.push_back(num);

    for(auto a:result){
        cout << a << "\n";
    }
}
 

// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/11653.cpp