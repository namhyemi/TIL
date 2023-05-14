// https://www.acmicpc.net/problem/18870
// 18870. 좌표 압축

#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> ori_arr;
vector<int> sort_arr;
vector<int> filter_arr;

int Binary_Search(int filter){
    int st = 0;
    int en = filter_arr.size();

    while(st < en){
        int mid = (st+en)/2;

        if(filter_arr[mid] < filter){
            st = mid + 1;
        }
        else{
            en = mid;
        }
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        ori_arr.push_back(num);
        sort_arr.push_back(num);
    }
    sort(sort_arr.begin(), sort_arr.end());
    for(int i=0; i<n; i++){
        if(i==0 || sort_arr[i] != sort_arr[i-1]){
            filter_arr.push_back(sort_arr[i]);
        }
    }

    for(int i=0; i<n; i++){
        cout << Binary_Search(ori_arr[i]) << " ";
    }
}

// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x13/solutions/18870.cpp
// iterator