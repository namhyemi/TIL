// https://www.acmicpc.net/problem/15688
// 15688번. 수 정렬하기5

#include<bits/stdc++.h>

using namespace std;

vector<int> v;

void InputUserDate(){
    int cnt;
    cin >> cnt;
    while(cnt--){
        int num;
        cin >> num;

        v.push_back(num);
    }
}

void OutputData(){
    for(int i=0; i < v.size() ;i++){
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