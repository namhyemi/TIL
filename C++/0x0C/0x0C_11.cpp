// https://www.acmicpc.net/problem/15666
// 15666번. N 과 M (12)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int result_arr[10];
int isused[10005];
vector<int> user_arr;

void func(int n){
    if(n==M){
        for(int i=0; i<M; i++) cout << result_arr[i] << " ";
        cout << "\n";
        return;
    }

    for(auto i : user_arr){
        if(n > 0 && result_arr[n-1] > i) continue;
        result_arr[n] = i;
        func(n+1);
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int tmp;
    for(int i=0; i<N; i++){ 
        cin >> tmp;
        if(isused[tmp] == 0) user_arr.push_back(tmp); // 배열에 숫자는 하나만 저장 
        isused[tmp]++; // 각 숫자가 몇번 등장했는지 저장
    }
    sort(user_arr.begin(), user_arr.end()); // 정렬

    func(0);
}


// 다른 해답
/*
#include <bits/stdc++.h>
using namespace std;

int arr[10];
int num[10];
int n, m;

void func(int k, int st){
  if(k == m){
    for(int i = 0; i < m; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  int tmp = -1;
  for(int i = st; i < n; i++){ // 이전 숫자랑 같은 수부터 시작
    if(num[i] != tmp){ // 똑같은 숫자 반복 출력 방지
      arr[k] = num[i];
      tmp = arr[k];
      func(k+1, i);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, num+n);
  func(0, 0);
}
*/