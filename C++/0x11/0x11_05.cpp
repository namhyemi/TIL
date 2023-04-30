// https://www.acmicpc.net/problem/1744
// 1744번. 수 묶기

#include <bits/stdc++.h>

using namespace std;

int money[1000005];

vector<int> minus_arr;
vector<int> zero_arr;
vector<int> one_arr;
vector<int> plus_arr;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    int num;
    while(cnt--){
        cin >> num;
        if(num < 0) minus_arr.push_back(num);
        else if(num == 0) zero_arr.push_back(num);
        else if(num == 1) one_arr.push_back(num);
        else plus_arr.push_back(num);
    }

    sort(minus_arr.begin(), minus_arr.end());
    sort(plus_arr.begin(), plus_arr.end());

    int sum = 0;
    int cur = 0;

    // 음수
    if(!minus_arr.empty()){
        while(cur < minus_arr.size() - 1){ 
            sum += minus_arr[cur] * minus_arr[cur+1];
            cur += 2;
        }

        // 0
        if(minus_arr.size() % 2 != 0 && zero_arr.size() == 0) sum += minus_arr[minus_arr.size()-1]; // 음수가 홀수개, 0이 없는 경우
    }
    // 1
    sum += one_arr.size();

    // 양수
    if(!plus_arr.empty()){
        cur = plus_arr.size() - 1; 
        while(cur > 0){
            sum += plus_arr[cur] * plus_arr[cur-1]; 
            cur -= 2; 
        }
        if(plus_arr.size() % 2 != 0) sum += plus_arr[0]; // 양수가 홀수개
    }
    cout << sum << "\n";
}

// 틀린 이유 : 계산 (음수는 오름순으로 정렬하면 절대값이 큰 값부터 정렬됨)
// 틀린 이유 : 런타임 에러(OutOfBounds) -> minus.size() 가 0인 경우 -1하면 -1이 아닌 다른 값이 나옴