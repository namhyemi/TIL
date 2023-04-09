// https://www.acmicpc.net/problem/15651
// 15650��. N �� M (2)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[10] = {0};
bool isused[10];

void func(int n){
    if(n==M){ // �� ����
        for(int i=0; i < M ; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i <= N; i++){
        if(!isused[i]){ // ��� ����
            if(n > 0 && arr[n-1] > i) continue; // �� ��° ���� ���ʹ� ���� ���ں��� ���� ��� �н�
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

// �Ǽ� : continue ��� �ϴµ� break ���

// �ٸ� �ع�(1)
/*
  int st = 1; // ��������, k = 0�� ������ st = 1
  if(k != 0) st = arr[k-1] + 1; // k != 0�� ��� st = arr[k-1]+1
  for(int i = st; i <= n; i++){ 
*/