// https://www.acmicpc.net/problem/15663
// 15663번. N 과 M (9)

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
        if(isused[i] > 0){ // 사용 횟수 확인
            isused[i]--;
            result_arr[n] = i;
            func(n+1);
            isused[i]++;
        }
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

/*
int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) { // 현재 k개까지 수를 택했음.
  if (k == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int tmp = 0;  // 중복 수열인지 확인 하기 위해 필요한 임시 변수
  for (int i = 0; i < n; ++i) {
    if (!isused[i] && tmp != num[i]){ // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
      isused[i] = true;
      arr[k] = num[i];
      tmp = arr[k];
      func(k + 1);
      isused[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num, num + n);
  func(0);
}
*/


