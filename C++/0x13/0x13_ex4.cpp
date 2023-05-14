// https://www.acmicpc.net/problem/2295
// 2295. 세 수의 합

#include<bits/stdc++.h>

using namespace std;

int arr[1005];
vector<int> two_sum;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){ cin >> arr[i];}

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            two_sum.push_back(arr[i]+arr[j]);
        }
    }

    sort(two_sum.begin(), two_sum.end());

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int a = arr[j] - arr[i];
            if(binary_search(two_sum.begin(), two_sum.end(), a)){
                result = max(result, arr[j]);
            }          
        }
    }
    cout << result << "\n";
}

// 다른 코드 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x13/solutions/2295.cpp