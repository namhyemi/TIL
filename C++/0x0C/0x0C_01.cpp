// https://www.acmicpc.net/problem/15651
// 15650번. N 과 M (2)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[10] = {0};
bool isused[10];

void func(int n){
    if(n==M){ // 총 개수
        for(int i=0; i < M ; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i <= N; i++){
        if(!isused[i]){ // 사용 여부
            if(n > 0 && arr[n-1] > i) continue; // 두 번째 숫자 부터는 이전 숫자보다 작을 경우 패스
            isused[i] = true;
            arr[n] = i;
            func(n+1);
            isused[i] = false;
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0);
}

// 실수 : continue 써야 하는데 break 사용

// 다른 해법(1)
/*
  int st = 1; // 시작지점, k = 0일 때에는 st = 1
  if(k != 0) st = arr[k-1] + 1; // k != 0일 경우 st = arr[k-1]+1
  for(int i = st; i <= n; i++){ 
*/