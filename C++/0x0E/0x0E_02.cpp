// https://www.acmicpc.net/problem/2751
// 2751번. 수 정렬하기2

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

/*
STL sort 는 quick sort 이지만 일반적으로 알고있는 구조에서 변형된 정렬로, 최악의 경우에도 O(NlogN) 유지.
*/