// https://www.acmicpc.net/problem/1193
// 1193. 분수찾기

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    int X = 0, Y = 0;
    for(int i=1; i<=10000000; i++){
        if(num > i) num -= i;
        else{
            if(i % 2 != 0){
                X = i - (num-1);
                Y = 1 + (num-1);                
            }
            else{
                X = 1 + (num-1);
                Y = i - (num-1);                
            }
            break;
        }
    }
    cout << X << "/" << Y << "\n";
}

// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/1193.cpp