// https://www.acmicpc.net/problem/9663
// 9663��. N-Queen

#include<bits/stdc++.h>

using namespace std;

int N, cnt=0;
bool isused_y[20];
bool isused_cross_plus[30];
bool isused_cross_minus[30];

void func(int x){
    if(x==N){ // ������ ����� ����
        cnt++;
        return;
    }

    for(int y=0; y < N; y++){
        if(!isused_y[y] && !isused_cross_plus[x+y] && !isused_cross_minus[x-y+N-1]){ // ����(�밢��, ����, ���� ��ġ�� ����)�� ������ ���
            isused_y[y] = true;
            isused_cross_plus[x+y] = true;
            isused_cross_minus[x-y+N-1] = true;
            func(x+1);
            isused_y[y] = false;
            isused_cross_plus[x+y] = false;
            isused_cross_minus[x-y+N-1] = false;            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << cnt;
}

/*
- �ð� ���⵵ : ���� ������ ���� O(N!) N = 14�� �� �ָ����� �����δ� �� ����. (����ġ��) => �����ϱ� �����
  N�� ���� �۾Ƽ� ��Ʈ��ŷ�ϰ� ���� ���� ���� �ð��� ���� �ɸ��� ���� ������ �������� �ð��ʰ� ������ Ȯ��
  
- Release ��� �˻�
*/