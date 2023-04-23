// https://www.acmicpc.net/problem/10825
// 10825번. 국영수

#include<bits/stdc++.h>

using namespace std;

int cnt;
vector<tuple<int,int,int, string>> students;

void InputUserDate(){
    cin >> cnt;

    string name;
    int kor, eng, math;
    for(int i=0; i<cnt ;i++){
        cin >> name >> kor >> eng >> math;
        students.push_back({-kor, eng, -math, name});
    }
}

void OutputData(){
    for(auto& s : students)
        cout << get<3>(s) << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
 
    InputUserDate();
    sort(students.begin(), students.end());
    OutputData();
}
