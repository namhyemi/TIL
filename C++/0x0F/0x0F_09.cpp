// https://www.acmicpc.net/problem/7795
// 7795π¯. ∏‘¿ª ∞Õ¿Œ∞° ∏‘»˙ ∞Õ¿Œ∞°

#include<bits/stdc++.h>

using namespace std;

vector<int> A, B;

void ClearVector(){
    A.clear();
    B.clear();
}

void InputUserDate(){
    int A_num, B_num, data;
    cin >> A_num >> B_num;

    while(A_num--){
        cin >> data;
        A.push_back(data);
    }
    while(B_num--){
        cin >> data;
        B.push_back(data);
    }
}

void SortData(){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

void Check(){
    int sum = 0, cnt = 0;
    for(int i=0; i<A.size(); i++){
        for(int j=cnt; j<B.size(); j++){
            if(A[i] > B[j]) cnt++;
            else { sum += cnt; break; }
        }
        if(cnt == B.size()) sum += cnt;
    }
    cout << sum << "\n";
}

void OutputData(){
    Check();
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    while(cnt--){
        ClearVector();
        InputUserDate();
        SortData();
        OutputData();
    }
}

