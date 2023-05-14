// https://www.acmicpc.net/problem/18869
// 18869. 멀티버스2

#include<bits/stdc++.h>

using namespace std;

int n, m;
int A[105][10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){ // 좌표 압축
        vector<int> tmp;
        for(int j=0; j < m; j++){
            cin >> A[i][j];
            
            tmp.push_back(A[i][j]);
        }
        sort(tmp.begin(), tmp.end());
        for(int j=0; j < m; j++){
            A[i][j] = lower_bound(tmp.begin(), tmp.end(), A[i][j]) - tmp.begin() ;
        }
    }

    int result = 0;
    for(int i=0; i < n-1; i++){ // 쌍 찾기
        for(int j=i+1; j < n; j++){
            int check = 1;
            for(int k=0; k < m; k++){
                if(A[i][k] != A[j][k]){
                    check = 0;
                }
            }
            if(check == 1){ result++; }
        }
    }

    cout <<  result << "\n";
}