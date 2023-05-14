// https://www.acmicpc.net/problem/1978
// 1978. �Ҽ� ã��

#include<bits/stdc++.h>

using namespace std;

int result = 0;

void Count(){
    int num;
    cin >> num;

    bool check = 1;
    if(num == 1) check = 0;
    else{
        for(int i=2; i*i <= num; i++){
            if(num % i == 0){
                check = 0;
                break;                
            }
        }
    }

    if(check == 1) result++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;

    cin >> cnt;

    for(int i=0; i<cnt; i++){
        Count();
    }

    cout << result << "\n";
}


// �ٸ� �ڵ� : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/1978.cpp