// https://www.acmicpc.net/problem/11651
// 11651번. 좌표 정렬하기2

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

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.Y < b.Y){
        return true;
    }
    else if(a.Y == b.Y){
        if(a.X < b.X) return true;
        else return false;
    }
    else return false;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    stable_sort(v.begin(), v.end(), cmp);
    OutputData();
}