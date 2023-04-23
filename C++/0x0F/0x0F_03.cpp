// https://www.acmicpc.net/problem/5648
// 5648번. 역원소 정렬

#include<bits/stdc++.h>

using namespace std;

vector<long long> v;

void Change(string &num){
    for(int i=0; i < num.length()/2; i++){
        swap(num[i], num[num.length()-1-i]);
    }
}

void InputUserDate(){
    int cnt;
    cin >> cnt;

    string num;
    while(cnt--){
        cin >> num;
        Change(num);
        v.push_back(stoll(num));
    }
}

void OutputData(){
    for(int i=0; i<v.size() ;i++){
        cout << v[i] << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    sort(v.begin(), v.end());
    OutputData();
}

// 틀린 이유 : 런타임 에러(out of range) - 정수형 범위 밖