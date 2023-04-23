// https://www.acmicpc.net/problem/1431
// 1431번. 시리얼 번호

#include<bits/stdc++.h>

using namespace std;

int len;
vector<string> arr;

void InputUserDate(){
    string text;
    cin >> len;
    for(int i=0; i < len ;i++){
        cin >> text; 
        arr.push_back(text);
    } 
}

bool Cmp(const string &a, const string &b){
    if(a.length() < b.length()) return true; // 길이순
    else if(a.length() == b.length()){ // 크기순
        int a_sum = 0, b_sum = 0;
        for(int i=0; i< a.length(); i++){
            if(a[i] >= 48 && a[i] < 58) a_sum += (a[i]-48);
            if(b[i] >= 48 && b[i] < 58) b_sum += (b[i]-48);
        }
        if(a_sum < b_sum) return true;
        else if(a_sum == b_sum){
            return a < b; // 사전순
        }
        else return false;
    }
    else return false;
}

void OutputData(){
    for(int i=0; i < arr.size() ;i++){
        cout << arr[i] << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    sort(arr.begin(), arr.end(), Cmp);
    OutputData();
}
