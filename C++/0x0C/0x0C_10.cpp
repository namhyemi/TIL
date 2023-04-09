// https://www.acmicpc.net/problem/15665
// 15665��. N �� M (11)

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
        if(isused[tmp] == 0) user_arr.push_back(tmp); // �迭�� ���ڴ� �ϳ��� ���� 
        isused[tmp]++; // �� ���ڰ� ��� �����ߴ��� ����
    }
    sort(user_arr.begin(), user_arr.end()); // ����

    func(0);
}

/*
// ���� -> while(n--) �ϰ� index �� ���� ������ ����� �Է� �迭�� ���� ���� ��� ����

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int k){ // ���� k������ ���� ������.
  if(k == m){ // m���� ��� ��������
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' '; // arr�� ����ص� �ε����� ������ ���� ���
    cout << '\n';
    return;
  }
  for(int i = 0; i < n; i++){ 
    arr[k] = i; // k��° ���� i�� ����
    func(k+1); // ���� ���� ���Ϸ� �� �ܰ� �� ��
  }
}

vector<bool> chk(10002);

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int idx = 0; // ���� ������ �ε���. �ߺ��� ���� ������ ����.
  while(n--){ 
    cin >> num[idx];
    if(chk[num[idx]]) continue; // �̹� ������ ���� ���� ��� �Ѿ
    chk[num[idx]] = true; // �׷��� ���� ��� ���� num �迭�� �߰�
    idx++;
  }
  // ���� num���� �ߺ����� ���� ���鸸 ���ְ� ���̴� idx.
  n = idx; // ���� ������� ����� ǥ���� ����ϱ� ���� n = idx�� ��.
  sort(num, num+n);
  func(0);
}

*/