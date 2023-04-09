// https://www.acmicpc.net/problem/15649
// 15649��. N �� M(1)

#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k){ // k�� ���� (�� ���� ����

    // base condition
    if(k==m){ // m�� ���� �Ϸ�
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }

    // ��Ʈ��ŷ(���)
    for(int i=1; i<=n; i++){
        if(!isused[i]){ // i �� ������ �ʾҴٸ�
            arr[k] = i; // k��°�� i ����
            isused[i] = 1; // ��� ǥ��
            func(k+1); // k+1�� ����
            isused[i] = 0; // �ٽ� i �� ����ϱ� ������ �ǵ���
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}