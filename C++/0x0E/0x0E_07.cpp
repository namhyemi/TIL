// https://www.acmicpc.net/problem/11650
// 11650번. 좌표 정렬하기1

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

vector<pair<int, int>> v;

void InputUserDate(){
    int cnt, num1, num2;
    cin >> cnt;
    while(cnt--){
        cin >> num1 >> num2;

        v.push_back({num1, num2});
    }
}

void OutputData(){
    for(int i=0; i < v.size() ;i++){
        cout << v[i].X << " " << v[i].Y << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    sort(v.begin(), v.end());
    OutputData();
}