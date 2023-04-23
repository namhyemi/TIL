// https://www.acmicpc.net/problem/10814
// 10814번. 나이순 정렬

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

vector<pair<int,string>> v;

void InputUserDate(){
    string name;
    int cnt, year;
    cin >> cnt;
    while(cnt--){
        cin >> year >> name;

        v.push_back({year, name});
    }
}

void OutputData(){
    for(int i=0; i < v.size() ;i++){
        cout << v[i].X << " " << v[i].Y  << "\n";
    }
}

bool cmp(pair<int,string> a, pair<int, string> b){
    return a.X < b.X;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    stable_sort(v.begin(), v.end(), cmp);
    OutputData();
}

// STL stabe_sort 는 merge sort