// https://www.acmicpc.net/problem/1822
// 1822. 차집합

#include<bits/stdc++.h>

using namespace std;

int n, m;
int n_arr[500005];
int m_arr[500005];

vector<int> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){ cin >> n_arr[i]; }
    for(int i=0; i<m; i++){ cin >> m_arr[i]; }

    sort(n_arr, n_arr+n);
    sort(m_arr, m_arr+m);

    for(int i=0; i<n; i++){
        if(!binary_search(m_arr, m_arr+m, n_arr[i])){
            result.push_back(n_arr[i]);
        }
    }

    cout << result.size() << "\n";
    if(!result.empty()){
        for(int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
    }
}

// 틀린 이유 : 조건 (출력 오름차순)