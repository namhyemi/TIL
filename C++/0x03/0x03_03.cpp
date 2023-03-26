// https://www.acmicpc.net/problem/3273
// 3273��. �� ���� ��

#include <bits/stdc++.h>

using namespace std;

int n[1000000] = {}; 
int x[2000000] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, cnt=0;


    cin >> a;
    for(int i=0; i < a; i++) cin >> n[i];
    cin >> b;
    
    for(int i=0; i < a ; i++)
    {
        if(b-n[i] > 0 && x[b-n[i]] == 1) cnt++;
        x[n[i]] = 1;
    }    
    cout << cnt << "\n";
}


// Ʋ�� ���� : �ð��ʰ� ( O(n^2) )
// Ʋ�� ���� : int n[1000000] �� ���������� �����ϸ� ����