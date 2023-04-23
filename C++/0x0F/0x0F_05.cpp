// https://www.acmicpc.net/problem/2910
// 2910¹ø. ºóµµ Á¤·Ä

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

vector<pair<int,int>> v;

void Check(int num){
    for(int i=0; i < v.size(); i++){
        if(v[i].X == num){
            v[i].Y++;
            return;
        }
    }
    v.push_back({num, 1});
}

void InputUserDate(){
    int cnt, max;
    cin >> cnt >> max;

    int num;
    while(cnt--){
        cin >> num;
        Check(num);
    }
}

void OutputData(){
    for(int i=0; i< v.size(); i++){
        for(int j=0; j<v[i].Y; j++)
            cout << v[i].X << " ";
    }    
}

bool Cmp(pair<int,int> a, pair<int,int> b){
    return a.Y > b.Y;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    stable_sort(v.begin(), v.end(), Cmp);
    OutputData();
}

