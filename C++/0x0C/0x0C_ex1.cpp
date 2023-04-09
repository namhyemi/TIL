// https://www.acmicpc.net/problem/15649
// 15649번. N 과 M(1)

#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k){ // k개 선택 (고른 숫자 개수

    // base condition
    if(k==m){ // m개 선택 완료
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }

    // 백트래킹(재귀)
    for(int i=1; i<=n; i++){
        if(!isused[i]){ // i 가 사용되지 않았다면
            arr[k] = i; // k번째로 i 선택
            isused[i] = 1; // 사용 표시
            func(k+1); // k+1개 선택
            isused[i] = 0; // 다시 i 를 사용하기 전으로 되돌림
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}