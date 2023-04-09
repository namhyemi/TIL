// https://www.acmicpc.net/problem/15665
// 15665번. N 과 M (11)

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

/*
// 참고 -> while(n--) 하고 index 는 따로 돌려서 사용자 입력 배열을 벡터 없이 사용 가능

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int k){ // 현재 k개까지 수를 택했음.
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' '; // arr에 기록해둔 인덱스를 참고해 값을 출력
    cout << '\n';
    return;
  }
  for(int i = 0; i < n; i++){ 
    arr[k] = i; // k번째 수를 i로 정함
    func(k+1); // 다음 수를 정하러 한 단계 더 들어감
  }
}

vector<bool> chk(10002);

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int idx = 0; // 수를 삽입할 인덱스. 중복된 수는 제거할 예정.
  while(n--){ 
    cin >> num[idx];
    if(chk[num[idx]]) continue; // 이미 이전에 수가 들어온 경우 넘어감
    chk[num[idx]] = true; // 그렇지 않은 경우 수를 num 배열에 추가
    idx++;
  }
  // 현재 num에는 중복되지 않은 수들만 들어가있고 길이는 idx.
  n = idx; // 이전 문제들과 비슷한 표현을 사용하기 위해 n = idx로 둠.
  sort(num, num+n);
  func(0);
}

*/