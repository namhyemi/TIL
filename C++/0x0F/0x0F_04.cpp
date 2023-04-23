// https://www.acmicpc.net/problem/1181
// 1181번. 단어 정렬

#include<bits/stdc++.h>

using namespace std;

vector<string> v;

bool Check(string s){
    for(int i=0; i < v.size(); i++){
        if(s == v[i]) return false;
    }
    return true;
}

void InputUserDate(){
    int cnt;
    cin >> cnt;

    string str;
    while(cnt--){
        cin >> str;
        if(Check(str)) v.push_back(str);
    }
}

void OutputData(){
    for(int i=0; i<v.size() ;i++){
        cout << v[i] << "\n";
    }
}

bool Cmp(const string &a, const string &b){
    if(a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    sort(v.begin(), v.end(), Cmp);
    OutputData();
}

