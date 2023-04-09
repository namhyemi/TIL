// https://www.acmicpc.net/problem/15663
// 15663��. N �� M (9)

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
        if(isused[i] > 0){ // ��� Ƚ�� Ȯ��
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
        if(isused[tmp] == 0) user_arr.push_back(tmp); // �迭�� ���ڴ� �ϳ��� ���� 
        isused[tmp]++; // �� ���ڰ� ��� �����ߴ��� ����
    }
    sort(user_arr.begin(), user_arr.end()); // ����

    func(0);
}

/*
int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) { // ���� k������ ���� ������.
  if (k == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int tmp = 0;  // �ߺ� �������� Ȯ�� �ϱ� ���� �ʿ��� �ӽ� ����
  for (int i = 0; i < n; ++i) {
    if (!isused[i] && tmp != num[i]){ // ���� ������ ������ �װ� ���ο� ������ ������ ���� ������ �ߺ� ����
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


