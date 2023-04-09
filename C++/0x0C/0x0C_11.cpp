// https://www.acmicpc.net/problem/15666
// 15666��. N �� M (12)

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
        if(isused[tmp] == 0) user_arr.push_back(tmp); // �迭�� ���ڴ� �ϳ��� ���� 
        isused[tmp]++; // �� ���ڰ� ��� �����ߴ��� ����
    }
    sort(user_arr.begin(), user_arr.end()); // ����

    func(0);
}


// �ٸ� �ش�
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
  for(int i = st; i < n; i++){ // ���� ���ڶ� ���� ������ ����
    if(num[i] != tmp){ // �Ȱ��� ���� �ݺ� ��� ����
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