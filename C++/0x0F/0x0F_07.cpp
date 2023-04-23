// https://www.acmicpc.net/problem/11656
// 11656번. 접미사 배열

#include<bits/stdc++.h>

using namespace std;

vector<string> v;
int a[26][1000];

void Check(string str){
    for(int i=0; i<str.length(); i++){
        v.push_back(str.substr(i, str.length()-i));
    }
}

void InputUserDate(){
    string str;
    cin >> str;
    Check(str);
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

