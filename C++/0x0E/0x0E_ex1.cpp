// https://www.acmicpc.net/problem/11728
// 11728번. 배열 합치기

#include<bits/stdc++.h>

using namespace std;

vector<int> arr1, arr2, arr3;

void InputUserDate(){
    int arr1_len, arr2_len, num;
    cin >> arr1_len >> arr2_len;

    while(arr1_len--){
        cin >> num;
        arr1.push_back(num);
    }
    while(arr2_len--){
        cin >> num;
        arr2.push_back(num);
    }
}

void MergeSort(){
    int arr1_idx=0, arr2_idx=0;
    int cnt = arr1.size() + arr2.size();

    while(cnt--){
        if(arr1_idx == arr1.size()){
            arr3.push_back(arr2[arr2_idx]);
            arr2_idx++;
        }
        else if(arr2_idx == arr2.size()){
            arr3.push_back(arr1[arr1_idx]);
            arr1_idx++;
        }
        else if(arr1[arr1_idx] <= arr2[arr2_idx]){
            arr3.push_back(arr1[arr1_idx]);
            arr1_idx++;
        }
        else if(arr1[arr1_idx] > arr2[arr2_idx]){
            arr3.push_back(arr2[arr2_idx]);
            arr2_idx++;
        }
    }
}

void OutputData(){
    for(int i=0; i < arr3.size() ;i++){
        cout << arr3[i] << " ";
    } cout << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    MergeSort();
    OutputData();
}

// 틀린 이유 : 시간 초과 => ios::sync_with_stdio(0);, cin.tie(0); (https://www.acmicpc.net/problem/15552)