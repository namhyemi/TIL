// guick sort
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

void quick_sort(int st, int en) { // arr[st to en-1]�� ������ ����
  if(en <= st+1) return; // ������ ���̰� 1 �����̸� �Լ� ����.(base condition)
  int pivot = arr[st]; // ���� ���� ���� pivot���� ��´�. ������ ���� ��� arr[st]�� swap�ص� �������.
  int l = st+1; // ������ l
  int r = en-1; // ������ r
  while(1){
    while(l <= r && arr[l] <= pivot) l++;
    while(l <= r && arr[r] >= pivot) r--;
    if(l > r) break; // l�� r�� �����Ǵ� �� ��� Ż��
    swap(arr[l], arr[r]);
  }
  swap(arr[st], arr[r]);
  quick_sort(st, r);
  quick_sort(r+1, en);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  quick_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
