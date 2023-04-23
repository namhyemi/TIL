// https://www.acmicpc.net/problem/11652
// 11652번. 카드

#include<bits/stdc++.h>

using namespace std;

int max_cnt = 0, cur_cnt = 0;
long long max_number;

vector<long long> v;

void InputUserDate(){
    int cnt;
    cin >> cnt;

    long long num;
    while(cnt--){
        cin >> num;
        v.push_back(num);
    }
}

void CheckMaxCard(){
    for(int i=0; i < v.size(); i++){
        if(i > 0 && v[i] != v[i-1]){
            if(max_cnt < cur_cnt){
                max_cnt = cur_cnt;
                max_number = v[i-1];
            }
            cur_cnt = 0;
        }
        cur_cnt++;
    }
    if(max_cnt < cur_cnt) max_number = v[v.size()-1];
}

void OutputData(){
    cout << max_number << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    sort(v.begin(), v.end());
    CheckMaxCard();
    OutputData();
}

// 툴린 이유 : 변수(long long)

// 시간 복잡도 => 정렬 : O(NlogN), 큰 수 찾기 : O(N) => O(NlogN)
// -(1ll << 62) - 1 : 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생
